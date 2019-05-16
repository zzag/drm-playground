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

class DrmAllocator : public QObject {
    Q_OBJECT

public:
    explicit DrmAllocator(QObject* parent = nullptr);
    ~DrmAllocator() override;

    /**
     * Returns whether this allocator is valid.
     */
    virtual bool isValid() const = 0;

    /**
     * Allocates an image.
     */
    virtual DrmImage* allocate(uint32_t width, uint32_t height, uint32_t format,
        const QVector<uint64_t>& modifiers) = 0;

private:
    Q_DISABLE_COPY(DrmAllocator)
};
