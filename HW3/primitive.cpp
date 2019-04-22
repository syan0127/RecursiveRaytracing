#include "primitive.h"
#include "lambertmaterial.h"

Primitive::Primitive()
{}

Primitive::Primitive(Shape *shape)
{
    m_shape_ptr = std::unique_ptr<Shape>(shape);
    Material *white_diffuse = new LambertMaterial();
    white_diffuse->m_baseColor = Color3f(1, 1, 1);
    m_material_ptr = std::unique_ptr<Material>(white_diffuse);
}

Primitive::Primitive(Light *light, Material *material)
{
    m_light_ptr = std::unique_ptr<Light>(light);
    m_material_ptr = std::unique_ptr<Material>(material);
}

Primitive::Primitive(Light *light, Shape *shape)
{
    m_light_ptr = std::unique_ptr<Light>(light);
    Material *white_diffuse = new LambertMaterial();
    white_diffuse->m_baseColor = Color3f(1, 1, 1);
    m_material_ptr = std::unique_ptr<Material>(white_diffuse);
    m_shape_ptr = std::unique_ptr<Shape>(shape);
}

Primitive::Primitive(Shape *shape, Material *material)
{
    m_shape_ptr = std::unique_ptr<Shape>(shape);
    m_material_ptr = std::unique_ptr<Material>(material);
}

//Primitive::Primitive(Shape *shape, const std::unique_ptr<Material> m)
//{
//    m_shape_ptr = std::unique_ptr<Shape>(shape);
//}




//function that returns whether there was an intersection between this primitive and the ray
bool Primitive::getIntersection(Ray r, Intersection *i) const
{
    if (!m_shape_ptr) {
        return false;
    }
    bool isIntersecting = m_shape_ptr->getIntersection(r, i);
    if (isIntersecting) {
        i->p_objectHit = this;
    }
    return isIntersecting;
}
