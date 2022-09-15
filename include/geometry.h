#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include <vector>

#include "util/matrix.h"
#include "intersection.h"
#include "ray.h"

class Sphere {
private:
	Matrix4d m_transformation;

public:
	Sphere(const Matrix4d& transformation);

	void transform(const Matrix4d& transformation);
	std::vector<double> intersect(const Ray& ray) const;
};

#endif // __GEOMETRY_H__