/*
 * Copyright (C) 2019 Vlad Zagorodniy <vladzzag@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "DrmGbmImage.h"
#include "DrmBuffer.h"
#include "DrmDevice.h"

#include <drm_fourcc.h>

DrmGbmImage::DrmGbmImage(DrmDevice* device, gbm_bo* bo)
    : m_bo(bo)
{
    const uint32_t width = gbm_bo_get_width(m_bo);
    const uint32_t height = gbm_bo_get_height(m_bo);
    const uint32_t format = gbm_bo_get_format(m_bo);

    std::array<uint32_t, 4> handles = { 0 };
    std::array<uint32_t, 4> strides = { 0 };
    std::array<uint32_t, 4> offsets = { 0 };
    std::array<uint64_t, 4> modifiers = { 0 };

    const int planeCount = gbm_bo_get_plane_count(m_bo);
    for (int i = 0; i < planeCount; ++i) {
        handles[i] = gbm_bo_get_handle_for_plane(m_bo, i).u32;
        strides[i] = gbm_bo_get_stride_for_plane(m_bo, i);
        offsets[i] = gbm_bo_get_offset(m_bo, i);
        modifiers[i] = gbm_bo_get_modifier(m_bo);
    }

    m_buffer = DrmBuffer::create(device, width, height, format, handles, strides,
        offsets, modifiers);
}

DrmGbmImage::~DrmGbmImage()
{
    delete m_buffer;
    gbm_bo_destroy(m_bo);
}

DrmBuffer* DrmGbmImage::buffer() const
{
    return m_buffer;
}
