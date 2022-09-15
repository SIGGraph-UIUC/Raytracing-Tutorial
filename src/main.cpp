#include <iostream>

#include "util/matrix.h"
#include "util/tuple.h"
#include "util/color.h"

#include "framebuffer.h"
#include "geometry.h"

int main() {
	int dimension = 1000;
	Framebuffer framebuffer{ dimension, dimension };

	Tuple4d ray_origin = point(0, 0, -5);
	Sphere sphere{ identity() };

	float canvas = 10;
	float pixel_size = canvas / dimension;
	for (int x = 0; x < dimension; ++x) {
		for (int y = 0; y < dimension; ++y) {
			float canvas_x = -5 + x * pixel_size;
			float canvas_y = 5 - y * pixel_size;
			float canvas_z = 10;
			Tuple4d canvas_pos = point(canvas_x, canvas_y, canvas_z);
			Ray ray{ ray_origin, canvas_pos - ray_origin };
			std::vector<double> intersections = sphere.intersect(ray);
			if (intersections.size() > 0) {
				framebuffer.write_color(x, y, Color(255, 255, 255));
			}
		}
	}
	framebuffer.write_to_ppm("test.ppm");
	std::cout << "Finished!" << std::endl;
}