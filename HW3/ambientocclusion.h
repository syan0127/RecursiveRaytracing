#ifndef AMBIENTOCCLUSION_H
#define AMBIENTOCCLUSION_H
#pragma once

#include "light.h"
#include "ray.h"
#include "warpfunctions.h"
#include "shape.h"
#include "sampler.h"
class AmbientOcclusion
{
public:
    AmbientOcclusion();
    AmbientOcclusion(int sample_count);

    bool applyAmbientOcclusion(const Intersection *i, Scene *s, Color3f &shadow);
    int m_sample_count;
    float m_distance;
    std::vector<float> m_samples;

};

#endif // AMBIENTOCCLUSION_H
