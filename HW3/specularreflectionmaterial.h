#ifndef SPECULARREFLECTIONMATERIAL_H
#define SPECULARREFLECTIONMATERIAL_H
#pragma once

#include "material.h"
#include "scene.h"
class SpecularReflectionMaterial : public Material
{
public:
    SpecularReflectionMaterial();
    SpecularReflectionMaterial(Color3f baseColor, Color3f color);
    virtual Color3f getScatteredColor(Ray r, int maxDepth, Intersection *i, Scene *s);
    Color3f getScatteredColorRecursive(Ray r, int maxDepth, Intersection *i, Scene *s);

    Color3f m_specular;
};

#endif // SPECULARREFLECTIONMATERIAL_H
