#ifndef __COLOR_H__
#define __COLOR_H__

#include <algorithm>
#include <ostream>

class Color
{
public:
    // attributes
    double r, g, b;

    Color(double r = 0, double g = 0, double b = 0);
};

// arithmetic overloads
Color operator*(const Color &lhs, double rhs);
Color operator/(const Color &lhs, double rhs);
Color operator+(const Color &lhs, const Color &rhs);
Color operator-(const Color &lhs, const Color &rhs);
Color& operator+=(Color &lhs, const Color &rhs);

// print overload
std::ostream& operator<<(std::ostream &out, const Color &rhs);

// utility function
Color hadamard_product(const Color &lhs, const Color &rhs);

#endif // __COLOR_H__
