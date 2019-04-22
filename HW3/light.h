#ifndef LIGHT_H
#define LIGHT_H
#pragma once

#include <globalincludes.h>
#include "intersection.h"
#include "transform.h"
#include "ray.h"

class Scene;

class Light
{
public:
    Light();
    Light(Color3f i, Transform t);
    virtual ~Light();
    virtual bool canSeeLight(const Intersection *i, Scene *s, Color3f &shadow) = 0;
    bool getIntersection(Ray r, Intersection *i, Scene *s) const;

    Color3f m_color;
    Transform m_transform;
    int m_id = 0;
};

#endif // LIGHT_H
