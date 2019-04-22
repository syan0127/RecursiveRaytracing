#ifndef SCENE_H
#define SCENE_H
#pragma once

#include <QList>
#include <primitive.h>
#include "light.h"
class Scene
{
public:
    Scene();
    bool getIntersection(Ray r, Intersection *i) const;

    std::vector<std::unique_ptr<Primitive>> m_primitives;
    std::vector<std::unique_ptr<Primitive>> m_lights;
};

#endif // SCENE_H
