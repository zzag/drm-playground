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

#include "DrmOutput.h"
#include "DrmConnector.h"
#include "DrmCrtc.h"
#include "DrmSwapchain.h"

DrmOutput::DrmOutput(DrmConnector* connector, QObject* parent)
    : QObject(parent)
    , m_connector(connector)
    , m_device(connector->device())
{
}

DrmOutput::~DrmOutput()
{
    delete m_swapchain;
}

DrmDevice* DrmOutput::device() const
{
    return m_device;
}

DrmConnector* DrmOutput::connector() const
{
    return m_connector;
}

DrmCrtc* DrmOutput::crtc() const
{
    return m_crtc;
}

DrmSwapchain* DrmOutput::swapchain() const
{
    return m_swapchain;
}

bool DrmOutput::isEnabled() const
{
    return m_isEnabled;
}

void DrmOutput::setEnabled(bool enabled)
{
    m_isEnabled = enabled;
}

void DrmOutput::createSwapchain()
{
    delete m_swapchain;

    // TODO: Actually create the swapchain.
}
