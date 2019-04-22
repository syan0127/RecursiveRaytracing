#include "camera.h"

Camera::Camera()
{}

Camera::Camera(Point3f eye,
               Point3f ref,
               Vector3f worldUp,
               float fovy,
               float near_clip,
               float far_clip,
               unsigned int width,
               unsigned int height) :
    m_eye(eye),
    m_ref(ref),
    m_worldUp(worldUp),
    m_fovy(fovy),
    m_near_clip(near_clip),
    m_far_clip(far_clip),
    m_width(width),
    m_height(height)
{
    RecomputeAttributes();
    m_view_project = getViewProj();
    m_view_project_inv = glm::inverse(m_view_project);
}

//function that returns ViewProjection matrix
glm::mat4 Camera::getViewProj()
{
    return glm::perspective(glm::radians(m_fovy),
                            m_width /
                            (float)m_height, m_near_clip, m_far_clip) *
                            glm::lookAt(m_eye, m_ref, m_up);
}

//function that takes in a pixel coordinate and return a Ray in
//world space that corresponds to the input pixel
Ray Camera::rayCast(Point2f &pixel)
{
    float sx = (2 * pixel.x / m_width) - 1;
    float sy = 1 - (2 * pixel.y / m_height);
    Point3f p = m_ref + sx * m_H + sy * m_V;

    Point3f origin = m_eye;
    Vector3f direction = glm::normalize(p - m_eye);

    return Ray(origin, direction);
}

//function that recompute camera attributes
void Camera::RecomputeAttributes()
{
    m_look = glm::normalize(m_ref - m_eye);
    m_right = glm::normalize(glm::cross(m_look, m_worldUp));
    m_up = glm::cross(m_right, m_look);

    float tan_fovy = tan(glm::radians(m_fovy / 2));
    float len = glm::length(m_ref - m_eye);
    m_aspect = m_width / m_height;
    m_V = m_up * len * tan_fovy;
    m_H = m_right * len * m_aspect * tan_fovy;
}
