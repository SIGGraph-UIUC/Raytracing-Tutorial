#include "camera.h"

Camera::Camera(int width, int height, double FOV) :
    m_width{ width },
    m_height{ height },
    m_FOV{ FOV },
    m_transformation{ identity() }
{
    double half_view = tan(m_FOV / 2);

    double aspect_ratio = (double)width / height;
    if (aspect_ratio >= 1)
    {
        m_half_width = half_view;
        m_half_height = half_view / aspect_ratio;
    }
    else
    {
        m_half_width = half_view * aspect_ratio;
        m_half_height = half_view;
    }
}

double Camera::pixel_size() const
{
    return (m_half_width * 2) / m_width;
}

void Camera::transform(const Matrix4d& transformation)
{
    m_transformation = transformation * m_transformation;
}

Ray Camera::ray(int x, int y) const
{
    double pix_size = pixel_size();
    double x_offset = (x + 0.5) * pix_size;
    double y_offset = (y + 0.5) * pix_size;

    double world_x = m_half_width - x_offset;
    double world_y = m_half_height - y_offset;

    Tuple4d pixel = m_transformation.inverse() * point(world_x, world_y, -1);
    Tuple4d origin = m_transformation.inverse() * point(0, 0, 0);
    Tuple4d direction = (pixel - origin).normalize();

    return Ray{ origin, direction };
}

Framebuffer Camera::render(const Scene& scene) const
{
    Framebuffer ret{ m_width, m_height };
    for (int y = 0; y < m_height; y++)
    {
        for (int x = 0; x < m_width; x++)
        {
            Ray shoot_ray = ray(x, y);
            Color color = scene.final_color(shoot_ray);
            ret.write_color(x, y, color);
        }
    }
    return ret;
}