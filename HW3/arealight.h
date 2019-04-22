#ifndef AREALIGHT_H
#define AREALIGHT_H
#pragma once

#include "light.h"
#include "ray.h"
#include "warpfunctions.h"
#include "shape.h"
#include "sampler.h"

class AreaLight : public Light
{
public:
    AreaLight();
    AreaLight(int sample_count, int id, Shape *shape);
    virtual ~AreaLight();
    virtual bool canSeeLight(const Intersection *i, Scene *s, Color3f &shadow);

    int m_sample_count;
    int m_id;
    Sampler m_sampler;
    Transform m_light_transform;

};

#endif // AREALIGHT_H
