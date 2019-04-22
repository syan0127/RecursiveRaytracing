#ifndef CAMERA_H
#define CAMERA_H

#pragma once

#include <globalincludes.h>
#include <ray.h>

class Camera
{
public:
    Camera();
    Camera(Point3f eye,
           Point3f ref,
           Vector3f worldUp,
           float fovy,
           float near_clip,
           float far_clip,
           unsigned int width,
           unsigned int height);

    Ray rayCast(Point2f &pixel);
    glm::mat4 getViewProj();
    void RecomputeAttributes();

    Point3f m_eye, m_ref;
    Vector3f m_worldUp, m_look, m_up, m_right;
    float m_fovy;
    float m_near_clip;
    float m_far_clip;
    unsigned int m_width, m_height;

    glm::mat4 m_view_project;
    glm::mat4 m_view_project_inv;
    float m_aspect;
    Vector3f m_V, m_H;

};

#endif // CAMERA_H
