#include "speculartransmissionmaterial.h"
#include "specularreflectionmaterial.h"

#define EPSILON 0.00005f
SpecularTransmissionMaterial::SpecularTransmissionMaterial() :
    IOR_in(1.0f), IOR_out(1.0f)
{
    Material::isTransmissive = true;
}

SpecularTransmissionMaterial::
    SpecularTransmissionMaterial(Color3f baseColor, float in, float out, Color3f color) :
    IOR_in(in), IOR_out(out), m_specular(color)
{
    Material::isTransmissive = true;
    m_baseColor = baseColor;
}

//wraper function to call recursive function getScatteredColorRecursive
Color3f SpecularTransmissionMaterial::
    getScatteredColor(Ray r, int maxDepth, Intersection *i, Scene *s)
{
    return getScatteredColorRecursive(r, maxDepth, i, s);
}

//refract the input Ray through the surface about the surface normal
//and evaluate GetScatteredColor at the point where the transmitted
//ray intersects the scene
Color3f SpecularTransmissionMaterial::
    getScatteredColorRecursive(Ray r, int maxDepth, Intersection *i, Scene *s)
{
    Color3f color(0);
    if (maxDepth == 0) {
        return color;
    }

    float eta = glm::dot(r.m_direction, i->m_normal) < 0
            ? IOR_out / IOR_in : IOR_in / IOR_out;
    bool isIn = true;
    if (glm::dot(r.m_direction, i->m_normal) < 0) {
        isIn = false;
    }

    Vector3f normalized_dir = glm::normalize(r.m_direction);
    Vector3f normalized_inter = glm::normalize(i->m_normal);
    float radicand = std::pow((eta), 2) *
            (1 - std::pow(-glm::dot(normalized_dir, normalized_inter), 2));

    //if radicant is greater than 1, there is internal reflection
    //otherwise there is refraction
    if (radicand > 1) {
        Color3f color(0);
        if (maxDepth == 0) {
            return color;
        }
        Vector3f offset;
        Vector3f reflected_ray_dir = glm::reflect(normalized_dir,
                                                  isIn ? -i->m_normal : i->m_normal);

        if(isIn) {
            offset = EPSILON * reflected_ray_dir;
        } else {
            offset = EPSILON * reflected_ray_dir;
        }
        Point3f reflected_ray_org = i->m_point + offset;
        Ray new_ray(reflected_ray_org, reflected_ray_dir);

        Intersection intersection = Intersection();
        if (!s->getIntersection(new_ray, &intersection)) {
            return color;
        };
        const Primitive *p = intersection.p_objectHit;
        if (p->m_material_ptr == nullptr) {
            return color;
        }
        color += m_baseColor *
                p->m_material_ptr->getScatteredColor(new_ray,
                                                     maxDepth - 1,
                                                     &intersection,
                                                     s);
        return color;
    }

    else {
        Vector3f offset;
        Vector3f refracted_ray_dir = glm::refract(normalized_dir,
                                                  isIn ? -i->m_normal : i->m_normal, eta);

        if (isIn) {
            offset = EPSILON * refracted_ray_dir;
        } else {
            offset = EPSILON * refracted_ray_dir;
        }
        Point3f refracted_ray_org = i->m_point + offset;
        Ray new_ray(refracted_ray_org, refracted_ray_dir);

        Intersection intersection = Intersection();
        if (!s->getIntersection(new_ray, &intersection)) {
            return color;
        };

        const Primitive *p = intersection.p_objectHit;
        if (p->m_material_ptr == nullptr) {
            return color;
        }
        color += m_baseColor * p->m_material_ptr->getScatteredColor(new_ray,
                                                                    maxDepth - 1,
                                                                    &intersection,
                                                                    s);
        return color;
    }
}

