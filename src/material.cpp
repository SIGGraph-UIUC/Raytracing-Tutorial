#include "material.h"

Material::Material(const Color& color, float ambient, float diffuse, float specular, float shininess) :
	m_color{ color },
	m_ambient{ ambient },
	m_diffuse{ diffuse },
	m_specular{ specular },
	m_shininess{ shininess }
{

}