#include "lambertmaterial.h"

LambertMaterial::LambertMaterial()
{}

LambertMaterial::LambertMaterial(Color3f color)
{
    m_baseColor = color;
}
// sample all light sources in the scene for their color
//(testing for visibility) and return the sum of their colors
//multiplied with the Material base color.
Color3f LambertMaterial::
    getScatteredColor(Ray r, int maxDepth, Intersection *i, Scene *s)
{
    Vector3f N = i->m_normal;
    Color3f color = Color3f(0.0f);
    float numLights = 0.0f;
    //iterate over the primitives in the scene and update diffuse term
    for (const auto & p : s->m_lights) {
//    for (const auto & p : s->m_primitives) {
//        if (p->m_light_ptr != nullptr) {
            numLights++;
            Color3f shadow(0.0f);
            if (p->m_light_ptr->canSeeLight(i, s, shadow)) {
                Vector3f light_pos = p->m_light_ptr->m_transform.m_translation;
                Vector3f L = glm::normalize(light_pos - i->m_point);
                float dot = glm::dot(N, L);
                dot = glm::clamp(dot, 0.f, 1.f);
                color += dot * shadow;

            }
//        }
    }


    color = m_baseColor * color / numLights;
    return color;
}


