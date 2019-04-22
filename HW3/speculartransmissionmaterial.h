#ifndef SPECULARTRANSMISSIONMATERIAL_H
#define SPECULARTRANSMISSIONMATERIAL_H
#pragma once

#include "material.h"
#include "scene.h"

class SpecularTransmissionMaterial : public Material
{
public:
    SpecularTransmissionMaterial();
    SpecularTransmissionMaterial(Color3f baseColor, float in, float out, Color3f color);
    virtual Color3f getScatteredColor(Ray r, int maxDepth, Intersection *i, Scene *s);
    Color3f getScatteredColorRecursive(Ray r, int maxDepth, Intersection *i, Scene *s);

    float IOR_in, IOR_out;
    Color3f m_specular;
};

#endif // SPECULARTRANSMISSIONMATERIAL_H
