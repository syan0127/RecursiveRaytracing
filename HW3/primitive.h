#ifndef PRIMITIVE_H
#define PRIMITIVE_H
#pragma once

#include <QString>
#include "shape.h"
#include "light.h"
#include "material.h"
//class Material;

class Primitive
{
public:
    Primitive();
    Primitive(Shape *shape);
    Primitive(Light *light, Material *material);
    Primitive(Light *light, Shape *shape);
    Primitive(Shape *shape, Material *material);

    bool getIntersection(Ray r, Intersection *i) const;

    QString m_name;
    std::unique_ptr<Shape> m_shape_ptr;
    std::unique_ptr<Light> m_light_ptr;
    std::unique_ptr<Material> m_material_ptr;
    Material * m_material;

};

#endif // PRIMITIVE_H
