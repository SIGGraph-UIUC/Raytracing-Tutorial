#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include <vector>

#include "util/tuple.h"
#include "util/matrix.h"
#include "intersection.h"
#include "material.h"
#include "ray.h"

class Sphere {
private:
	Matrix4d m_transformation;
	Material m_material;

public:
	Sphere(const Matrix4d& transformation, const Material& material);

	const Material& material() const { return m_material; }

	void transform(const Matrix4d& transformation);
	std::vector<double> intersect(const Ray& ray) const;
	Tuple4d normal(const Tuple4d& hit_point) const;
};

#endif // __GEOMETRY_H__