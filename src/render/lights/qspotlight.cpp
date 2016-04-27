/****************************************************************************
**
** Copyright (C) 2014 Klaralvdalens Datakonsult AB (KDAB).
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qspotlight.h"
#include "qspotlight_p.h"
#include <Qt3DCore/qnodepropertychange.h>

QT_BEGIN_NAMESPACE

namespace Qt3DRender {


/*
  Expected Shader struct

  \code

  struct SpotLight
  {
   vec3 position;
   vec3 localDirection;
   vec4 color;
   float intensity;
   float cutOffAngle;
  };

  uniform SpotLight spotLights[10];

  \endcode
 */

QSpotLightPrivate::QSpotLightPrivate()
    : QAbstractLightPrivate(QAbstractLight::SpotLight)
{
    m_shaderData->setProperty("constantAttenuation", 0.0f);
    m_shaderData->setProperty("linearAttenuation", 0.0f);
    m_shaderData->setProperty("quadraticAttenuation", 0.0f);
    m_shaderData->setProperty("direction", QVector3D(0.0f, -1.0f, 0.0f));
    m_shaderData->setProperty("cutOffAngle", 45.0f);
}

/*!
  \class Qt3DRender::QSpotLight
  \inmodule Qt3DRender
  \since 5.5

 */

/*!
    \qmltype SpotLight
    \instantiates Qt3DRender::QSpotLight
    \inherits AbstractLight
    \inqmlmodule Qt3D.Render
    \since 5.5
    \brief For OpenGL ...
*/

/*! \fn void Qt3DRender::QSpotLight::copy(const Qt3DCore::QNode *ref)
  Copies the \a ref instance into this one.
 */

void QSpotLight::copy(const QNode *ref)
{
    QAbstractLight::copy(ref);
}


/*!
  \fn Qt3DRender::QSpotLight::QSpotLight(Qt3DCore::QNode *parent)
  Constructs a new QSpotLight with the specified \a parent.
 */
QSpotLight::QSpotLight(QNode *parent)
    : QAbstractLight(*new QSpotLightPrivate, parent)
{
}

/*! \internal */
QSpotLight::QSpotLight(QSpotLightPrivate &dd, QNode *parent)
    : QAbstractLight(dd, parent)
{
}

/*!
  \qmlproperty vector3d Qt3D.Render::SpotLight::localDirection

*/

/*!
  \property Qt3DRender::QSpotLight::localDirection

 */

float QSpotLight::constantAttenuation() const
{
    Q_D(const QSpotLight);
    return d->m_shaderData->property("constantAttenuation").toFloat();
}

void QSpotLight::setConstantAttenuation(float value)
{
    Q_D(QSpotLight);
    if (constantAttenuation() != value) {
        d->m_shaderData->setProperty("constantAttenuation", value);
        emit constantAttenuationChanged(value);
    }
}

float QSpotLight::linearAttenuation() const
{
    Q_D(const QSpotLight);
    return d->m_shaderData->property("linearAttenuation").toFloat();
}

void QSpotLight::setLinearAttenuation(float value)
{
    Q_D(QSpotLight);
    if (linearAttenuation() != value) {
        d->m_shaderData->setProperty("linearAttenuation", value);
        emit linearAttenuationChanged(value);
    }
}

float QSpotLight::quadraticAttenuation() const
{
    Q_D(const QSpotLight);
    return d->m_shaderData->property("quadraticAttenuation").toFloat();
}

void QSpotLight::setQuadraticAttenuation(float value)
{
    Q_D(QSpotLight);
    if (quadraticAttenuation() != value) {
        d->m_shaderData->setProperty("quadraticAttenuation", value);
        emit quadraticAttenuationChanged(value);
    }
}

QVector3D QSpotLight::localDirection() const
{
    Q_D(const QSpotLight);
    return d->m_shaderData->property("direction").value<QVector3D>();
}


/*!
  \qmlproperty float Qt3D.Render::SpotLight::cutOffAngle

*/

/*!
  \property Qt3DRender::QSpotLight::cutOffAngle

 */
float QSpotLight::cutOffAngle() const
{
    Q_D(const QSpotLight);
    return d->m_shaderData->property("cutOffAngle").toFloat();
}

void QSpotLight::setLocalDirection(const QVector3D &direction)
{
    Q_D(QSpotLight);
    if (localDirection() != direction) {
        d->m_shaderData->setProperty("direction", direction);
        emit localDirectionChanged(direction);
    }
}

void QSpotLight::setCutOffAngle(float value)
{
    Q_D(QSpotLight);
    if (cutOffAngle() != value) {
        d->m_shaderData->setProperty("cutOffAngle", value);
        emit cutOffAngleChanged(value);
    }
}

} // namespace Qt3DRender

QT_END_NAMESPACE
