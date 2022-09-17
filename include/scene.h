#ifndef __SCENE_H__
#define __SCENE_H__

#include <vector>

#include "light.h"
#include "geometry.h"
#include "payload.h"

class Scene {
private:
	std::vector<PointLight> m_lights;
	std::vector<Sphere> m_objects;

public:
	void add_light(const PointLight& light);
	void add_sphere(const Sphere& sphere);

	bool shadow(const PointLight& light, const Tuple4d& position) const;
	std::vector<Intersection> intersections(const Ray& ray) const;

	Color shade(const Payload& payload) const;
	Color final_color(const Ray& ray) const;
};

#endif // __SCENE_H__