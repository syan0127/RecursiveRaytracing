#include "scene.h"

Scene::Scene()
{}

//function tests the input Ray for intersection with all Primitives in the Scene
//and outputs the Intersection with the smallest non-negative t value via the
//Intersection* input to the function. It should return false if the Ray
//does not intersect any geometry.
bool Scene::getIntersection(Ray r, Intersection *i) const {

    float min = std::numeric_limits<float>::max();
    bool hasIntersection = false;
    Intersection minIsect;
    for (int x = 0; x < m_primitives.size(); ++x) {
        if (m_primitives.at(x)->getIntersection(r, i)){
            float temp_t = i->t;
            if(min > temp_t && temp_t > 0.0f) {
                minIsect = *i;
                min = temp_t;
            }
            hasIntersection = true;
        }
    }

    if (hasIntersection) {
        *i = minIsect;
        return true;
    }
    return false;
}
