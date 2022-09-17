#include "scene.h"

void Scene::add_light(const PointLight& light)
{
	m_lights.push_back(light);
}

void Scene::add_sphere(const Sphere& sphere)
{
	m_objects.push_back(sphere);
}

std::vector<Intersection> Scene::intersections(const Ray& ray) const
{
    std::vector<Intersection> ret;
    for (int i = 0; i < m_objects.size(); i++)
    {
        std::vector<double> object_intersects = m_objects[i].intersect(ray);
        for (int j = 0; j < object_intersects.size(); j++) {
            ret.emplace_back(object_intersects[j], m_objects[i]);
        }
    }
    std::sort(ret.begin(), ret.end());
    return ret;
}

bool Scene::shadow(const PointLight& light, const Tuple4d& position) const
{
    Tuple4d light_dir = light.direction(position);
    double distance = light_dir.magnitude();
    Tuple4d normalized_light_dir = light_dir.normalize();

    std::vector<Intersection> xs = intersections(Ray{ position, normalized_light_dir });
    int i = hit(xs);
    if (i >= 0)
        return (xs[i].t() < distance);
    else
        return false;
}

Color Scene::shade(const Payload& payload) const
{
    Color ret{ 0, 0, 0 };

    // surface
    for (int i = 0; i < m_lights.size(); i++)
    {
        bool shadowed = shadow(m_lights.at(i), payload.over_point());
        if (!shadowed)
            ret += m_lights[i].phong_shading(payload.object(), payload.point(), payload.eye(), payload.normal());
    }

    return ret;
}

Color Scene::final_color(const Ray& ray) const
{
    std::vector<Intersection> xs = intersections(ray);
    int intersect = hit(xs);
    if (intersect >= 0)
        return shade(Payload{ ray, xs[intersect] });
    else
        return Color{ 0, 0, 0 };
}