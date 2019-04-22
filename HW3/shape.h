#ifndef SHAPE_H
#define SHAPE_H
#pragma once

#include <transform.h>
#include <ray.h>
#include <intersection.h>
class Shape
{
public:
    Shape();
    Shape(Transform t);
    virtual ~Shape();
    virtual bool getIntersection(Ray r, Intersection *i) const = 0;

    Transform m_transform;
    int m_id = 0;
};

#endif // SHAPE_H
