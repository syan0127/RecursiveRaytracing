#ifndef LAMBERTMATERIAL_H
#define LAMBERTMATERIAL_H
#pragma once

#include "material.h"
#include "scene.h"
class LambertMaterial : public Material
{
public:
    LambertMaterial();
    LambertMaterial(Color3f color);
    virtual Color3f getScatteredColor(Ray r, int maxDepth, Intersection *i, Scene *s);

};

#endif // LAMBERTMATERIAL_Hß
