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

#include <QList>
#include <QMap>
#include <QSet>

class DrmAllocator;
class DrmBlob;
class DrmBuffer;
class DrmConnector;
class DrmCrtc;
class DrmDevice;
class DrmImage;
class DrmMode;
class DrmOutput;
class DrmPlane;
class DrmSwapchain;

typedef QList<DrmConnector*> DrmConnectorList;
typedef QList<DrmCrtc*> DrmCrtcList;
typedef QList<DrmDevice*> DrmDeviceList;
typedef QList<DrmImage*> DrmImageList;
typedef QList<DrmMode> DrmModeList;
typedef QList<DrmOutput*> DrmOutputList;
typedef QList<DrmPlane*> DrmPlaneList;

typedef QMap<DrmConnector*, DrmCrtc*> DrmCrtcMap;

typedef QSet<DrmConnector*> DrmConnectorSet;

enum AllocatorType {
    AllocatorDumb,
    AllocatorGbm
};

enum Dpms {
    DpmsOn,
    DpmsStandby,
    DpmsSuspend,
    DpmsOff
};

enum PlaneType {
    PlanePrimary,
    PlaneOverlay,
    PlaneCursor,
};
