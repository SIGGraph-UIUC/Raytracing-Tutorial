#include "material.h"

Material::Material() :
	m_color{ Color{1, 1, 1} },
	m_ambient{ 0.1 },
	m_diffuse{ 0.9 },
	m_specular{ 0.2 },
	m_shininess{ 0.2 }
{
}

Material::Material(const Color& color, float ambient, float diffuse, float specular, float shininess) :
	m_color{ color },
	m_ambient{ ambient },
	m_diffuse{ diffuse },
	m_specular{ specular },
	m_shininess{ shininess }
{

}