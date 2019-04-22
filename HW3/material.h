#ifndef MATERIAL_H
#define MATERIAL_H
#pragma once

#include "globalincludes.h"
#include "ray.h"
#include "intersection.h"
#include "scene.h"

class Material
{
public:
    Material();
    virtual Color3f getScatteredColor(Ray r, int maxDepth, Intersection *i, Scene *s) = 0;

    Color3f m_baseColor;
    bool isTransmissive = false;
};

#endif // MATERIAL_H
