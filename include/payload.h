#ifndef __PAYLOAD_H__
#define __PAYLOAD_H__

#include "util/tuple.h"

#include "intersection.h"
#include "geometry.h"

class Payload {
private:
    Sphere m_object;
    Tuple4d m_point, m_eye, m_normal, m_reflected, m_over_point;
    double m_t;

public:
    Payload(const Ray& ray, const Intersection& intersection);

    const Sphere& object() const { return m_object; }
    const Tuple4d& point() const { return m_point; }
    const Tuple4d& eye() const { return m_eye; }
    const Tuple4d& normal() const { return m_normal; }
    const Tuple4d& reflected() const { return m_reflected; }
    const Tuple4d& over_point() const { return m_over_point; }
    double t() const { return m_t; }
};

#endif // __PAYLOAD_H__