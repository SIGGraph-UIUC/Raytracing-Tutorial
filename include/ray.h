#ifndef __RAY_H__
#define __RAY_H__

#include "util/matrix.h"
#include "util/tuple.h"

class Ray {
private:
	Tuple4d m_origin, m_direction;

public:
	Ray(const Tuple4d& origin, const Tuple4d& direction);

	const Tuple4d& origin() const { return m_origin; }
	const Tuple4d& direction() const { return m_direction; }

	Tuple4d position(double t) const;
	Ray transform(const Matrix4d& transformation) const;
};

#endif // __RAY_H__