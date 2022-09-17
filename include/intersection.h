#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "geometry.h"
#include "ray.h"

class Intersection {
private:
	double m_t;
	Sphere m_object;

public:
	Intersection(double t, const Sphere& object);

	double t() const { return m_t; }
	const Sphere& object() const { return m_object; }

	friend bool operator<(const Intersection& i1, const Intersection& i2);
	friend bool operator==(const Intersection& i1, const Intersection& i2);
};

int hit(const std::vector<Intersection>& intersections);

#endif // __INTERSECTION_H__