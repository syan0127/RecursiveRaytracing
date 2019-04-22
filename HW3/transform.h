#ifndef TRANSFORM_H
#define TRANSFORM_H

#pragma once
#include <globalincludes.h>

class Transform
{
public:
    Transform();
    Transform(const glm::vec3 &t, const glm::vec3 &r, const glm::vec3 &s);

    glm::vec3 m_translation, m_rotation, m_scale;
    glm::mat4 m_worldTransform, m_worldTransformInverse;
    glm::mat3 m_worldTransformInverseTranspose;

};

#endif // TRANSFORM_H
