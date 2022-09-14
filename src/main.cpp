#include <iostream>

#include "util/matrix.h"
#include "util/tuple.h"
#include "util/color.h"

#include "framebuffer.h"

int main() {
	Framebuffer framebuffer{ 100, 100 };
	for (int x = 25; x < 50; ++x) {
		for (int y = 25; y < 50; ++y) {
			framebuffer.write_color(x, y, Color(255, 255, 255));
		}
	}
	framebuffer.write_to_ppm("test.ppm");
	std::cout << "Finished!" << std::endl;
}