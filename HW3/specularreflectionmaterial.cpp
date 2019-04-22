#include "specularreflectionmaterial.h"

SpecularReflectionMaterial::SpecularReflectionMaterial()
{}

SpecularReflectionMaterial::SpecularReflectionMaterial(Color3f baseColor, Color3f color) :
    m_specular(color)
{
    m_baseColor = baseColor;
}

//wrapper function to call recursive function getScatteredColorRecursive
Color3f SpecularReflectionMaterial::
    getScatteredColor(Ray r, int maxDepth, Intersection *i, Scene *s)
{
    return getScatteredColorRecursive(r, maxDepth, i, s);
}

//reflect the input Ray r about the surface normal and evaluate
//GetScatteredColor at the point where the reflected Ray intersects the scene
Color3f SpecularReflectionMaterial::
    getScatteredColorRecursive(Ray r, int maxDepth, Intersection *i, Scene *s)
{
    Color3f color(0);
    if(maxDepth == 0) return color;

    //computes reflected ray
    Point3f reflected_ray_org = i->m_point + 0.001f * i->m_normal;
    Vector3f reflected_ray_dir = glm::reflect(r.m_direction, i->m_normal);
    Ray new_ray(reflected_ray_org, reflected_ray_dir);

    //if there is no intersection, return color
    Intersection intersection = Intersection();
    if (!s->getIntersection(new_ray, &intersection)) {
        return color;
    };

    //otherwise, if the intersected object has material, update color by
    //recursive call
    const Primitive *p = intersection.p_objectHit;
    if (p->m_material_ptr == nullptr) {
        return color;
    }

    color = m_baseColor
            * p->m_material_ptr->getScatteredColor(new_ray,
                                                   maxDepth - 1,
                                                   &intersection,
                                                   s);
    return color;
}
