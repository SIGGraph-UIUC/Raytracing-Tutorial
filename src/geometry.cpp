#include "geometry.h"

Sphere::Sphere(const Matrix4d& transformation, const Material& material) : 
	m_transformation{ transformation },
    m_material{ material }
{

}

Sphere::Sphere(const Sphere& other)
{
    m_transformation = other.m_transformation;
    m_material = other.m_material;
}

void Sphere::transform(const Matrix4d& transformation)
{
    m_transformation = m_transformation * transformation;;
}

std::vector<double> Sphere::intersect(const Ray& ray) const
{
    Ray transformed_ray = ray.transform(m_transformation.inverse());
    Tuple4d sphere_to_ray = transformed_ray.origin() - point(0, 0, 0);
    double a = dot(transformed_ray.direction(), transformed_ray.direction());
    double b = 2 * dot(transformed_ray.direction(), sphere_to_ray);
    double c = dot(sphere_to_ray, sphere_to_ray) - 1;
    double discriminant = pow(b, 2) - 4 * a * c;

    std::vector<double> intersects;
    if (discriminant >= 0)
    {
        intersects.push_back((-b + sqrt(discriminant)) / (2 * a));
        intersects.push_back((-b - sqrt(discriminant)) / (2 * a));
    }
    return intersects;
}

Tuple4d Sphere::normal(const Tuple4d& hit_point) const
{
    Tuple4d transformed_point = m_transformation.inverse() * hit_point;
    Tuple4d object_normal = transformed_point - point(0, 0, 0);
    Tuple4d world_normal = m_transformation.inverse().transpose() * object_normal;
    world_normal(3) = 0;
    return world_normal.normalize();
}