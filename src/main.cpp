#include <iostream>

#include "util/matrix.h"
#include "util/tuple.h"
#include "util/color.h"

#include "framebuffer.h"
#include "geometry.h"
#include "light.h"

int main() {
	int dimension = 1000;
	Framebuffer framebuffer{ dimension, dimension };

	Tuple4d ray_origin = point(0, 0, -5);
	Sphere sphere{ identity() , Material{Color(1, 0.2, 1), 0.1, 0.9, 0.9, 200} };
	PointLight light{ point(-10, 10, -10), Color{1, 1, 1} };

	float canvas = 10;
	float pixel_size = canvas / dimension;
	for (int x = 0; x < dimension; ++x) {
		for (int y = 0; y < dimension; ++y) {
			float canvas_x = -5 + x * pixel_size;
			float canvas_y = 5 - y * pixel_size;
			float canvas_z = 10;
			Tuple4d canvas_pos = point(canvas_x, canvas_y, canvas_z);
			Ray ray{ ray_origin, (canvas_pos - ray_origin).normalize() };
			std::vector<double> intersections = sphere.intersect(ray);
			if (intersections.size() > 0) {
				std::sort(intersections.begin(), intersections.end());
				float t_min = FLT_MAX;
				for (int i = 0; i < intersections.size(); ++i) {
					if (intersections[i] > 0 && intersections[i] < t_min) {
						t_min = intersections[i];
					}
				}

				Tuple4d point = ray.position(t_min);
				Tuple4d normal = sphere.normal(point);
				Tuple4d eye = -ray.direction();
				Color color = light.phong_shading(sphere, point, eye, normal);
				framebuffer.write_color(x, y, color);
			}
		}
	}
	framebuffer.write_to_ppm("test.ppm");
	std::cout << "Finished!" << std::endl;
}