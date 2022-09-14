#include "framebuffer.h"

Framebuffer::Framebuffer(int width, int height) : 
    m_width{ width }, 
    m_height{ height } 
{
    for (int y = 0; y < height; ++y) {
        m_buffer.push_back(std::vector<Color>());
        for (int x = 0; x < width; ++x) {
            m_buffer[y].push_back(Color(0, 0, 0));
        }
    }
}

void Framebuffer::write_color(int x, int y, const Color& color)
{
    m_buffer[y][x] = color;
}

void Framebuffer::write_to_ppm(const std::string& name)
{
    std::ofstream output(name, std::ofstream::trunc);

    // standard P3 output
    output << "P3" << '\n'
           << m_width << ' ' << m_height << '\n'
           << 255 << '\n';

    for (int y = 0; y < m_height; y++)
    {
        for (int x = 0; x < m_width; x++)
        {
            output << m_buffer[y][x];
        }
        output << '\n';
    }

    output.close();
}