#include "util/tuple.h"

Tuple4d::Tuple4d()
{
    for (int i = 0; i < 4; i++)
    {
        m_buffer[i] = 0;
    }
}

// copy overloads
Tuple4d::Tuple4d(const Tuple4d& rhs)
{
    for (int i = 0; i < 4; i++)
    {
        m_buffer[i] = rhs(i);
    }
}

Tuple4d& Tuple4d::operator=(const Tuple4d& rhs)
{
    if (&rhs == this)
        return *this;

    for (int i = 0; i < 4; i++)
    {
        m_buffer[i] = rhs(i);
    }

    return *this;
}

// accessor methods
double& Tuple4d::operator()(const size_t idx)
{
    assert(idx < 4 && "index out of bounds");
    return m_buffer[idx];
}

const double& Tuple4d::operator()(const size_t idx) const
{
    assert(idx < 4 && "index out of bounds");
    return m_buffer[idx];
}

// tuple logic
double Tuple4d::magnitude() const
{
    double total = 0;
    for (int i = 0; i < 4; i++)
    {
        total += pow(m_buffer[i], 2);
    }
    return sqrt(total);
}

Tuple4d Tuple4d::normalize() const
{
    double scalar = magnitude();

    Tuple4d ret{};
    for (int i = 0; i < 4; i++)
    {
        ret(i) = m_buffer[i] / scalar;
    }
    return ret;
}

// arithmetic overloads
Tuple4d operator-(const Tuple4d& rhs)
{
    Tuple4d ret;
    for (int i = 0; i < 4; i++)
    {
        ret(i) = -rhs(i);
    }
    return ret;
}

Tuple4d operator+(const Tuple4d& lhs, const Tuple4d& rhs)
{
    Tuple4d ret;
    for (int i = 0; i < 4; i++)
    {
        ret(i) = lhs(i) + rhs(i);
    }
    return ret;
}

Tuple4d operator-(const Tuple4d& lhs, const Tuple4d& rhs)
{
    Tuple4d ret;
    for (int i = 0; i < 4; i++)
    {
        ret(i) = lhs(i) - rhs(i);
    }
    return ret;
}

Tuple4d operator*(const Tuple4d& lhs, double s)
{
    Tuple4d ret;
    for (int i = 0; i < 4; i++)
    {
        ret(i) = lhs(i) * s;
    }
    return ret;
}

Tuple4d operator/(const Tuple4d& lhs, double s)
{
    return lhs * (1 / s);
}


Tuple4d& operator+=(Tuple4d& lhs, const Tuple4d& rhs)
{
    for (int i = 0; i < 4; i++)
    {
        lhs(i) += rhs(i);
    }

    return lhs;
}

// utility functions
Tuple4d reflect(const Tuple4d& in, const Tuple4d& normal)
{
    return in - normal * 2 * dot(in, normal);
}

double dot(const Tuple4d& lhs, const Tuple4d& rhs)
{
    double total = 0;
    for (int i = 0; i < 4; i++)
    {
        total += lhs(i) * rhs(i);
    }
    return total;
}

Tuple4d cross(const Tuple4d& lhs, const Tuple4d& rhs)
{
    return vector(lhs(1) * rhs(2) - lhs(2) * rhs(1),
        lhs(2) * rhs(0) - lhs(0) * rhs(2),
        lhs(0) * rhs(1) - lhs(1) * rhs(0));
}

// convenience functions
Tuple4d point(double x, double y, double z)
{
    Tuple4d ret;
    ret(0) = x;
    ret(1) = y;
    ret(2) = z;
    ret(3) = 1;
    return ret;
}

Tuple4d vector(double x, double y, double z)
{
    Tuple4d ret;
    ret(0) = x;
    ret(1) = y;
    ret(2) = z;
    ret(3) = 0;
    return ret;
}