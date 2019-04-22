#include "light.h"
#include "scene.h"

Light::Light()
{
    m_color = Point3f(0);
    m_transform = Transform();
}

Light::Light(Color3f i, Transform t)
{
    m_color = i;
    m_transform = t;
}

Light::~Light()
{}

//function that checks if there is an intersection;if the material of intersected
//primitive skip
bool Light::getIntersection(Ray r, Intersection *i, Scene *s) const {
    float min = std::numeric_limits<float>::max();
    bool hasIntersection = false;
    Intersection minIsect;
    for (int x = 0; x < s->m_primitives.size(); ++x){
        if (s->m_primitives.at(x)->m_material_ptr->isTransmissive) continue;
        if (s->m_primitives.at(x)->getIntersection(r, i)) {
            float temp_t = i->t;
            if(min > temp_t) {
                minIsect = *i;
                min = temp_t;
            }
            hasIntersection = true;
        }
    }

    for (int x = 0; x < s->m_lights.size(); ++x){
        if (s->m_lights.at(x)->m_material_ptr->isTransmissive) continue;
        if (s->m_lights.at(x)->getIntersection(r, i)) {
            float temp_t = i->t;
            if(min > temp_t) {
                minIsect = *i;
                min = temp_t;
            }
            hasIntersection = true;
        }
    }

    if (hasIntersection) {
        *i = minIsect;
        return true;
    }
    return false;
}
