#ifndef INTERSECTION_H
#define INTERSECTION_H

#pragma once

#include <globalincludes.h>
//#include <primitive.h>
class Primitive;
class Material;
class Intersection
{
public:
    Intersection();

    Point3f m_point;
    Normal3f m_normal;
    float t;
    const Primitive *p_objectHit;

};

#endif // INTERSECTION_H
