#include "sphere.h"

Sphere::Sphere() : m_origin(Point3f(0, 0, 0)), m_radius(0.5f)
{}

Sphere::~Sphere()
{}

//function that return true if there is an intersection between the
//input ray and this sphere
bool Sphere::getIntersection(Ray r, Intersection *i) const
{
    Ray t_ray = r.transformRay(Shape::m_transform.m_worldTransformInverse);
    Point3f R_0 = t_ray.m_origin;
    Vector3f R_d = t_ray.m_direction;
    float A = R_d.x * R_d.x + R_d.y * R_d.y + R_d.z * R_d.z;
    float B = 2 * (R_d.x * (R_0.x - m_origin.x) +
                   R_d.y * (R_0.y - m_origin.y) +
                   R_d.z * (R_0.z - m_origin.z));
    float C = (R_0.x - m_origin.x) *(R_0.x - m_origin.x) +
                (R_0.y - m_origin.y) *(R_0.y - m_origin.y) +
                (R_0.z - m_origin.z) *(R_0.z - m_origin.z) -
                m_radius * m_radius;

    //check d
    float D = B * B - 4 * A * C;
    if (D < 0) return false;
    float t;

    if (D < FLT_EPSILON) {
        t = -B / (2 * A);
        if(t < 0) return false;
    } else if (D > 0) {
        float t1 = (-B + sqrt(D)) / (2 * A);
        float t2 = (-B - sqrt(D)) / (2 * A);

        if (t1 < 0 && t2 < 0) return false;
        if (t1 < 0) t = t2;
        else if (t2 < 0) t = t1;
        else t = std::min(t1, t2);

    }

    Point3f P = R_0 + t * R_d;
    glm::vec4 temp_p(P.x, P.y, P.z, 1.0f);
    Normal3f N = glm::vec3(glm::normalize(P));

    temp_p = Shape::m_transform.m_worldTransform * temp_p;
    P = Point3f(temp_p.x, temp_p.y, temp_p.z);
    N = glm::normalize(Shape::m_transform.m_worldTransformInverseTranspose * N);
    i->m_point = P;
    i->m_normal = N;
    i->t = t;

    return true;
}

