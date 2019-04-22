#include "transform.h"

Transform::Transform() : Transform(glm::vec3(0), glm::vec3(0), glm::vec3(1))
{}

Transform::Transform(const glm::vec3 &t, const glm::vec3 &r, const glm::vec3 &s) :
    m_translation(t),
    m_rotation(r),
    m_scale(s)
{
    glm::mat4 transMat = glm::translate(glm::mat4(1.0f), m_translation);
    glm::mat4 x_rotMat = glm::rotate(glm::mat4(1.0f),  (m_rotation.x), glm::vec3(1,0,0));
    glm::mat4 y_rotMat = glm::rotate(glm::mat4(1.0f),  (m_rotation.y), glm::vec3(0,1,0));
    glm::mat4 z_rotMat = glm::rotate(glm::mat4(1.0f),  (m_rotation.z), glm::vec3(0,0,1));
    glm::mat4 scaleMat = glm::scale(glm::mat4(1.0f), m_scale);

    m_worldTransform = transMat * x_rotMat * y_rotMat * z_rotMat * scaleMat;

    m_worldTransformInverse = glm::inverse(m_worldTransform);

    glm::mat3 temp_world = glm::mat3(m_worldTransform);
    m_worldTransformInverseTranspose = glm::inverse(glm::transpose(temp_world));
}
