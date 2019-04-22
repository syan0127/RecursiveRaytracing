#include "ray.h"

Ray::Ray()
{
    m_origin = glm::vec3(0, 0, 0);
    m_direction = glm::vec3(0, 0, 0);
}

Ray::Ray(Point3f origin, Vector3f direction)
{
    m_origin = origin;
    m_direction = direction;
}

//function that takes in a 4D transformation matrix and returns a new Ray that is
//the result of transforming this Ray by that transformation matrix
Ray Ray::transformRay(glm::mat4 mat)
{
    glm::vec4 temp_origin = mat * glm::vec4(m_origin, 1.0f);

    glm::vec4 temp_direction = mat * glm::vec4(m_direction, 0.0f);

    Point3f new_origin = Point3f(temp_origin.x, temp_origin.y, temp_origin.z);
    Vector3f new_direction = Vector3f(temp_direction.x, temp_direction.y, temp_direction.z);

    return Ray(new_origin, new_direction);
}
