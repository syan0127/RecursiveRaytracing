#include "disc.h"

Disc::Disc() :
    m_origin(Point3f(0, 0, 0)),
    m_radius(0.5f),
    m_normal(Vector3f(0, 0, 1))
{
    m_id = 2;
}

Disc::~Disc()
{}

//function that return returns if there is an intersection between
//the input ray and this disc
bool Disc::getIntersection(Ray r, Intersection *i) const
{
    Ray t_ray = r.transformRay(Shape::m_transform.m_worldTransformInverse);
    Point3f R_o = t_ray.m_origin;
    Vector3f R_d = t_ray.m_direction;

    float t = glm::dot(m_normal, m_origin - R_o) /
                glm::dot(m_normal, R_d);

    if (t < 0) {
        return false;
    }

    Point3f P = R_o + t * R_d;
    //check if it lies within the radius
    if(P.x * P.x + P.y * P.y > m_radius * m_radius) {
        return false;
    }

    glm::vec4 temp_p(P.x, P.y, P.z, 1);
    temp_p = Shape::m_transform.m_worldTransform * temp_p;
    P = Point3f(temp_p.x, temp_p.y, temp_p.z);
    Normal3f N = (Shape::m_transform.m_worldTransformInverseTranspose
                  * m_normal);

    i->m_point = P;
    i->m_normal = N;
    i->t = t;

    return true;

}
