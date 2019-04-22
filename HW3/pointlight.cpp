#include "pointlight.h"
#include "ray.h"
#include "scene.h"
#include "primitive.h"

PointLight::PointLight()
{}

PointLight::~PointLight()
{}

//function that, given an Intersection in the scene, determines
//if that Intersection can see the Light
bool PointLight::canSeeLight(const Intersection *i, Scene *s, Color3f &shadow)
{
    Point3f light_pos = m_transform.m_translation;
    Point3f intersection_pos = i->m_point;

    //compute new ray from intersection point to light
    Point3f R_0 = intersection_pos + 0.001f * i->m_normal;
    Vector3f R_d = glm::normalize(light_pos - intersection_pos);
    Ray ray(R_0, R_d);
    Intersection intersection = Intersection();

    shadow = m_color;
    //return true if there is no intersection along the new ray
    if (!getIntersection(ray, &intersection, s)) {
        return true;
    }
    //if the distance from light position to new intersection position is
    //less than distance from original intersection and new
    //intersection the object can see light
    if (glm::length(light_pos - intersection_pos) <
            glm::length(intersection.m_point - intersection_pos)) {
        return true;
    } else {
        return false;
    }
}

