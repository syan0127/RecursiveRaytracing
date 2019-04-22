#include "arealight.h"
#include "shape.h"
#include "scene.h"

AreaLight::AreaLight() : m_sample_count(1024)
{}

AreaLight::AreaLight(int sample_count, int id, Shape *shape) :
    m_sample_count(sample_count), m_id(id)
{
    if (shape->m_id == 1) {
        m_sampler.generateSamples(m_sample_count,
                                  GRID,
                                  NONE);
    } else {
        m_sampler.generateSamples(m_sample_count,
                                  STRATIFIED,
                                  DISC_UNIFORM);
    }
    m_light_transform = shape->m_transform;
}

AreaLight::~AreaLight()
{}

//function that determines whether intersection point can see the area light
//and update shadow color
bool AreaLight::canSeeLight(const Intersection *i, Scene *s, Color3f &shadow)
{
    Point3f intersection_pos = i->m_point;

    std::vector<float> samples = m_sampler.peekSamples();

    float count = 0.f;

    for (int j = 0; j < samples.size(); j += 3) {
        glm::vec3 sample_pos = glm::vec3(samples.at(j),
                                         samples.at(j + 1),
                                         samples.at(j + 2));
        sample_pos.y -= 0.5f;
        sample_pos.x -= 0.5f;
        glm::vec4 temp_pos = glm::vec4(sample_pos, 1.f);
        temp_pos = m_light_transform.m_worldTransform * temp_pos;
        sample_pos.x = temp_pos.x;nm
        sample_pos.y = temp_pos.y;
        sample_pos.z = temp_pos.z;

        Intersection intersection = Intersection();

        Point3f ro = intersection_pos + 0.0001f * i->m_normal;
        Vector3f rd = glm::normalize(sample_pos - intersection_pos);
        Ray ray = Ray(ro, rd);

        // check if the ray intersects the area light
        bool intersects = getIntersection(ray, &intersection, s);
        if (intersects && intersection.p_objectHit->m_light_ptr.get() == this) {
                count++;
        }
    }

    if (count < 1.f) {
        return false;
    }

    float ratio = count / m_sample_count;

    //update shadow
    shadow = ratio * m_color;

    return true;
}

