#include "ambientocclusion.h"
#include "scene.h"

AmbientOcclusion::AmbientOcclusion() : m_sample_count(16), m_distance(.5f)
{}

AmbientOcclusion::AmbientOcclusion(int sample_count) :
    m_sample_count(sample_count),
    m_distance(.5f)
{
    Sampler sampler = Sampler();
    sampler.generateSamples(m_sample_count, STRATIFIED, HEMISPHERE_UNIFORM);

    //get sample positions
     m_samples = sampler.peekSamples();

}

//function that applies ambient occlusion
bool AmbientOcclusion::
    applyAmbientOcclusion(const Intersection *i, Scene *s, Color3f &shadow)
{
    Point3f intersection_pos = i->m_point;

    Color3f color(0);

    for (int j = 0; j < m_samples.size(); j += 3) {
        glm::vec3 sample_pos = glm::vec3(m_samples.at(j),
                                         m_samples.at(j + 1),
                                         m_samples.at(j + 2));

        Point3f ro = intersection_pos + 0.0001f * i->m_normal;

        Vector3f normal = i->m_normal;
        Vector3f tangent = glm::cross(Vector3f(0, 1, 0), normal);
        Vector3f bitangent = glm::cross(normal, tangent);
        glm::mat4 trans_mat (glm::normalize(glm::vec4(tangent, 0)),
                             glm::normalize(glm::vec4(bitangent, 0)),
                             glm::normalize(glm::vec4(normal, 0)),
                             glm::vec4(0, 0, 0, 1));

        //compute transformation matrix
        trans_mat = glm::translate(glm::mat4(), i->m_point) * trans_mat;

        //get transforemd sample position
        glm::vec4 temp_samplepos = trans_mat * glm::vec4(sample_pos, 1);
        Vector3f rd = glm::normalize(glm::vec3(temp_samplepos) - intersection_pos);

        //create a ray from intersection point to the transforemd sample pos
        Ray ray = Ray(ro, rd);

        Intersection intersection = Intersection();
        bool isIntersecting = s->getIntersection(ray, &intersection);

        //if t value is less than 0.5 add black
        if (isIntersecting && intersection.t < m_distance) {
            continue;
        }

        //otherwise add white
        color += Color3f(1);
    }

    shadow = color / (float)m_sample_count;
    return true;
}
