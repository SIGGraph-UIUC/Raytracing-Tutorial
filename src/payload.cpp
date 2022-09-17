#include "payload.h"

Payload::Payload(const Ray& ray, const Intersection& intersection) :
	m_t{ intersection.t() },
	m_object{ intersection.object() },
	m_eye{ -ray.direction() }
{
	m_point = ray.position(m_t);
	m_normal = m_object.normal(m_point);
	m_reflected = reflect(ray.direction(), m_normal);
	m_over_point = m_point + m_normal * 0.001;
}