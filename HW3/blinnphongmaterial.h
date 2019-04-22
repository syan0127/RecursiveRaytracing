#ifndef BLINNPHONGMATERIAL_H
#define BLINNPHONGMATERIAL_H
#pragma once

#include "material.h"
#include "scene.h"
class BlinnPhongMaterial : public Material
{
public:
    BlinnPhongMaterial();
    BlinnPhongMaterial(Color3f baseColor, float shininess, Color3f color);
    virtual Color3f getScatteredColor(Ray r, int maxDepth, Intersection *i, Scene *s);

    float m_shininess, m_weight;
    Color3f m_specular;
};

#endif // BLINNPHONGMATERIAL_H
