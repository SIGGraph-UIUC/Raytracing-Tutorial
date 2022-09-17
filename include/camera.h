#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "util/matrix.h"

#include "ray.h"
#include "framebuffer.h"
#include "scene.h"

class Camera {
private:
    int m_width, m_height;
    double m_FOV;
    Matrix4d m_transformation;
    double m_half_width, m_half_height;

    // helper function
    double pixel_size() const;

public:
    Camera(int width, int height, double FOV);

    void transform(const Matrix4d& transformation);

    Ray ray(int x, int y) const;
    Framebuffer render(const Scene& scene) const;
};

#endif // __CAMERA_H__