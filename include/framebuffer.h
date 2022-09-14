#ifndef __FRAMEBUFFER_H__
#define __FRAMEBUFFER_H__

#include <fstream>
#include <string>
#include <vector>

#include "util/color.h"

class Framebuffer {
private:
	int m_width, m_height;
	std::vector<std::vector<Color>> m_buffer;

public:
	Framebuffer(int width, int height);

	void write_color(int x, int y, const Color& color);
	void write_to_ppm(const std::string& filename);
};

#endif // __FRAMEBUFFER_H__