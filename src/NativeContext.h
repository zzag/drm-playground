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

#include <memory>

class DrmDeviceManager;
class DrmOutputManager;
class SessionController;
class UdevContext;

class NativeContext : public QObject {
    Q_OBJECT

public:
    explicit NativeContext(QObject* parent = nullptr);
    ~NativeContext() override;

    /**
     * Whether this context is valid.
     */
    bool isValid() const;

    /**
     * Returns the DRM device manager.
     */
    DrmDeviceManager* deviceManager() const;

    /**
     * Returns the output manager.
     */
    DrmOutputManager* outputManager() const;

    /**
     * Returns the session controller.
     */
    SessionController* sessionController() const;

    /**
     * Returns the udev context.
     */
    UdevContext* udev() const;

    /**
     * Returns desired buffer allocator.
     */
    AllocatorType allocatorType() const;

private:
    DrmDeviceManager* m_deviceManager = nullptr;
    DrmOutputManager* m_outputManager = nullptr;
    SessionController* m_sessionController = nullptr;
    std::unique_ptr<UdevContext> m_udev;
    AllocatorType m_allocatorType = AllocatorGbm;

    Q_DISABLE_COPY(NativeContext)
};
