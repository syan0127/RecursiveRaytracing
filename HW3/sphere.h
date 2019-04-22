#ifndef SPHERE_H
#define SPHERE_H
#pragma once
#include <shape.h>
#include <math.h>
#include <glm/gtc/type_ptr.hpp>
#include<iostream>

class Sphere : public Shape
{
public:
    Sphere();
    virtual ~Sphere();
    virtual bool getIntersection(Ray r, Intersection *i) const;

    Point3f m_origin;
    float m_radius;
};

#endif // SPHERE_H
