#ifndef DISC_H
#define DISC_H
#pragma once
#include <shape.h>

class Disc : public Shape
{
public:
    Disc();
    virtual ~Disc();
    virtual bool getIntersection(Ray r, Intersection *i) const;

    Point3f m_origin;
    float m_radius;
    Vector3f m_normal;
};

#endif // DISC_H
