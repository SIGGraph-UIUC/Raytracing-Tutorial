#include "light.h"

PointLight::PointLight(const Tuple4d& position, const Color& intensity) :
	m_position{ position },
	m_intensity{ intensity }
{

}

Tuple4d PointLight::direction(const Tuple4d& hit_point) const
{
	return (m_position - hit_point).normalize();
}

Color PointLight::phong_shading(const Sphere& object, const Tuple4d& position, const Tuple4d& eye, const Tuple4d& normal) const
{
	Color ret{ 0, 0, 0 };

	Material mat = object.material();
	Color effective_color = hadamard_product(mat.color(), m_intensity);

	Tuple4d light_direction = direction(position);
	double light_dot_normal = dot(light_direction, normal);
	if (light_dot_normal >= 0)
	{
		Color diffuse = effective_color * mat.diffuse() * light_dot_normal;

		Tuple4d reflect_direction = reflect(-light_direction, normal);
		double reflect_dot_eye = dot(reflect_direction, eye);
		if (reflect_dot_eye <= 0)
			ret += diffuse;
		else
		{
			Color specular = m_intensity * mat.specular() * pow(reflect_dot_eye, mat.shininess());
			ret += diffuse + specular;
		}
	}

	ret += effective_color * mat.ambient();
	return ret;
}