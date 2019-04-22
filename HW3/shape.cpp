#include "shape.h"

Shape::Shape()
{
    m_transform = Transform();
}

Shape::Shape(Transform t)
{
    m_transform = t;
}

Shape::~Shape()
{}
