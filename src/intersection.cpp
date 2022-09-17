#include "intersection.h"

Intersection::Intersection(double t, const Sphere& object) :
	m_t{ t },
	m_object{ object }
{

}

bool operator<(const Intersection& i1, const Intersection& i2)
{
	return (i1.m_t < i2.m_t);
}

bool operator==(const Intersection& i1, const Intersection& i2)
{
	return (i1.m_t == i2.m_t);
}

int hit(const std::vector<Intersection>& intersections)
{
	for (int i = 0; i < intersections.size(); i++)
	{
		if (intersections.at(i).t() > 0)
			return i;
	}

	return -1;
}