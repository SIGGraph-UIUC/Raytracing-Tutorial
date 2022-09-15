#include "geometry.h"

Sphere::Sphere(const Matrix4d& transformation) : 
	m_transformation{ transformation }
{

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