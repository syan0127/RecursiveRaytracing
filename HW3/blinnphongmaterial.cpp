#include "blinnphongmaterial.h"
#include "globalincludes.h"

BlinnPhongMaterial::BlinnPhongMaterial()
{
    m_shininess = 4000;
    m_weight = 0.5;
    m_specular = Color3f(1);
}

BlinnPhongMaterial::BlinnPhongMaterial(Color3f baseColor, float shininess, Color3f color)
{
    m_shininess = shininess;
    m_weight = 0.5;
    m_specular = color;
    m_baseColor = baseColor;
}

//function that computes the direction(s) from which light should reach a
//point of intersection
Color3f BlinnPhongMaterial::
    getScatteredColor(Ray r, int maxDepth, Intersection *i, Scene *s)
{
    Vector3f N = i->m_normal;
    Color3f diffuse(0);
    float numLights = 0.0f;

    //iterate over the primitives in the scene and update diffuse term
    for (const auto & p : s->m_primitives) {
        if (p->m_light_ptr != NULL) {
            numLights++;
            Color3f shadow_color = Color3f(0);
            if (p->m_light_ptr->canSeeLight(i, s, shadow_color)) {
                Vector3f light_pos = p->m_light_ptr->m_transform.m_translation;
                Vector3f L = glm::normalize(light_pos - i->m_point);
                float dot = glm::dot(N, L);
                dot = glm::clamp(dot, 0.f, 1.f);
                diffuse += dot * p->m_light_ptr->m_color;
            }
        }
    }

    diffuse /= numLights;
    Color3f specular = m_specular;

    //iterate over the primitives and update specular term
    for (const auto & p : s->m_primitives) {
        if (p->m_light_ptr != NULL) {
            Color3f shadow_color = Color3f(0);
            if (p->m_light_ptr->canSeeLight(i, s, shadow_color)) {
                Vector3f light_pos = p->m_light_ptr->m_transform.m_translation;
                Vector3f L = glm::normalize(light_pos - i->m_point);
                Vector3f V = r.m_origin - i->m_point;
                Vector3f H = glm::normalize(L + V);
                float dot = glm::clamp(glm::dot(N, H), 0.f, 1.f);
                specular *= std::pow(dot, m_shininess);
            }
        }
    }

    specular /= numLights;

    //update return color using diffuse and specular colors found above
    Color3f color =  m_baseColor *
            ((1 - m_weight) * diffuse + m_weight * specular);
    return color;
}
