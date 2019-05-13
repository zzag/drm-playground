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

#pragma once

#include "globals.h"

#include <QObject>

#include <gbm.h>

class DrmAllocator : public QObject {
    Q_OBJECT

public:
    explicit DrmAllocator(DrmDevice* device, QObject* parent = nullptr);
    ~DrmAllocator();

    /**
     * Returns whether this allocator is valid.
     */
    bool isValid() const;

    /**
     * Allocates an image.
     */
    DrmImage* allocate(uint32_t width, uint32_t height, uint32_t format,
        const QVector<uint64_t>& modifiers);

private:
    DrmDevice* m_device = nullptr;
    gbm_device* m_gbm = nullptr;

    Q_DISABLE_COPY(DrmAllocator)
};
