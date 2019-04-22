#ifndef POINTLIGHT_H
#define POINTLIGHT_H
#pragma once

#include "light.h"
#include "ray.h"

class PointLight : public Light
{
public:
    PointLight();
    virtual ~PointLight();
    virtual bool canSeeLight(const Intersection *i, Scene *s, Color3f &shadow);
};

#endif // POINTLIGHT_H
