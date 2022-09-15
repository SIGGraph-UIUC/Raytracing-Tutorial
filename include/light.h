#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "util/color.h"
#include "util/tuple.h"

#include "geometry.h"

class PointLight {
private:
	Tuple4d m_position;
	Color m_intensity;

public:
	PointLight(const Tuple4d& position, const Color& intensity);

	Tuple4d direction(const Tuple4d& hit_point) const;
	Color phong_shading(const Sphere& object, const Tuple4d& position, const Tuple4d& eye, const Tuple4d& normal) const;
};

#endif // __LIGHT_H__