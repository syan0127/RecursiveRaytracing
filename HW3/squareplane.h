#ifndef SQUAREPLANE_H
#define SQUAREPLANE_H
#pragma once
#include <shape.h>

class SquarePlane : public Shape
{
public:
    SquarePlane();
    virtual ~SquarePlane();
    virtual bool getIntersection(Ray r, Intersection *i) const;

    Point3f m_origin;
    float m_length;
    Vector3f m_normal;
};

#endif // SQUAREPLANE_H
