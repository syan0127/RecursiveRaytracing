#ifndef RAY_H
#define RAY_H
#pragma once

#include <globalincludes.h>

class Ray
{
public:
    Ray();
    Ray(Point3f origin, Vector3f direction);
    Ray transformRay(glm::mat4 mat);

    Point3f m_origin;
    Vector3f m_direction;
};

#endif // RAY_H
