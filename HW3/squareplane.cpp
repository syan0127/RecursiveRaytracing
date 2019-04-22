#include "squareplane.h"

SquarePlane::SquarePlane() :
    m_origin(Point3f(0, 0, 0)),
    m_length(1),
    m_normal(Vector3f(0, 0, 1))
{
    m_id = 1;
}

SquarePlane::~SquarePlane()
{}

//function that returns true if there is an intersection between
//the input ray and this squareplane
bool SquarePlane::getIntersection(Ray r, Intersection *i) const
{
    Ray t_ray = r.transformRay(Shape::m_transform.m_worldTransformInverse);
    Point3f R_0 = t_ray.m_origin;
    Vector3f R_d = t_ray.m_direction;

    float t;
    t = glm::dot(m_normal, m_origin - R_0) /
            glm::dot(m_normal, R_d);

    if (t < 0) {
        return false;
    }

    Point3f P = R_0 + t * R_d;
    float minx = m_origin.x - m_length / 2.0f;
    float maxx = m_origin.x + m_length / 2.0f;
    float miny = m_origin.y - m_length / 2.0f;
    float maxy = m_origin.y + m_length / 2.0f;

    if (P.x < minx || P.x > maxx || P.y < miny || P.y > maxy) {
        return false;
    }
    glm::vec4 temp_p(P.x, P.y, P.z, 1);
    temp_p = Shape::m_transform.m_worldTransform * temp_p;
    P = Point3f(temp_p.x, temp_p.y, temp_p.z);
    Normal3f N = (Shape::m_transform.m_worldTransformInverseTranspose * m_normal);

    i->m_point = P;
    i->m_normal = N;
    i->t = t;

    return true;
}
