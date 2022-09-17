#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "util/color.h"

class Material {
private:
	Color m_color;
	float m_ambient, m_diffuse, m_specular, m_shininess;

public:
	Material();
	Material(const Color& color, float ambient, float diffuse, float specular, float shininess);

	const Color& color() const { return m_color; }
	float ambient() const { return m_ambient; }
	float diffuse() const { return m_diffuse; }
	float specular() const { return m_specular; }
	float shininess() const { return m_shininess; }
};

#endif // __MATERIAL_H__