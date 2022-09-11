#include "util/color.h"

Color::Color(double r, double g, double b) :
    r{ r },
    g{ g },
    b{ b }
{}

// arithmetic overloads
Color operator*(const Color& lhs, double rhs)
{
    return Color{ lhs.r * rhs, lhs.g * rhs, lhs.b * rhs };
}

Color operator/(const Color& lhs, double rhs)
{
    return lhs * (1 / rhs);
}

Color operator+(const Color& lhs, const Color& rhs)
{
    return Color{ lhs.r + rhs.r, lhs.g + rhs.g, lhs.b + rhs.b };
}

Color operator-(const Color& lhs, const Color& rhs)
{
    return Color{ lhs.r - rhs.r, lhs.g - rhs.g, lhs.b - rhs.b };
}

Color& operator+=(Color& lhs, const Color& rhs)
{
    lhs.r += rhs.r;
    lhs.g += rhs.g;
    lhs.b += rhs.b;
    return lhs;
}

// print overload
std::ostream& operator<<(std::ostream& out, const Color& rhs)
{
    out << std::clamp((int)(rhs.r * 256), 0, 255) << ' ';
    out << std::clamp((int)(rhs.g * 256), 0, 255) << ' ';
    out << std::clamp((int)(rhs.b * 256), 0, 255) << ' ';

    return out;
}

// utility function
Color hadamard_product(const Color& lhs, const Color& rhs)
{
    return Color{ lhs.r * rhs.r, lhs.g * rhs.g, lhs.b * rhs.b };
}