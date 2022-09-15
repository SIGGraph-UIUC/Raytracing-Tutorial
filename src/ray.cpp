#include "ray.h"

Ray::Ray(const Tuple4d& origin, const Tuple4d& direction) :
    m_origin{ origin },
    m_direction{ direction }
{};

Tuple4d Ray::position(double t) const
{
    return m_origin + m_direction * t;
}

Ray Ray::transform(const Matrix4d& transformation) const
{
    return Ray{ transformation * m_origin, transformation * m_direction };
}