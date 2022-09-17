#include <iostream>

#include "util/matrix.h"
#include "util/tuple.h"
#include "util/color.h"

#include "camera.h"
#include "framebuffer.h"
#include "geometry.h"
#include "light.h"

int main() {
	int dimension = 1000;

	Camera camera{ dimension, dimension, 3.1415 / 2 };
	Tuple4d up = vector(0, 1, 0);
	Tuple4d from = point(0, 1.5, -5);
	Tuple4d to = point(0, 1, 0);
	camera.transform(view(from, to, up));

	Sphere sphere{ identity() , Material{Color(1, 0.2, 1), 0.1, 0.9, 0.9, 200} };
	Sphere sphere2{ identity().translate(0, 2, 0), Material{Color(1, 1, 1), 0.1, 0.9, 0.9, 150} };
	PointLight light{ point(-10, 10, -10), Color{1, 1, 1}, 2 };

	Scene scene;
	scene.add_light(light);
	scene.add_sphere(sphere);
	scene.add_sphere(sphere2);

	Framebuffer result = camera.render(scene);
	result.write_to_ppm("test.ppm");
	std::cout << "Finished!" << std::endl;
}