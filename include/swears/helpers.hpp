#ifndef _SWEARS_HELPERS_HPP_
#define _SWEARS_HELPERS_HPP_

#include <stdexcept>

namespace Swears
{
    class Vec2
    {
    public:
        Vec2() : Vec2(0,0) {};
        Vec2(int x, int y) : x(x), y(y) {};
        Vec2 operator+(const Vec2& other) { return {x + other.x, y + other.y}; };
        Vec2 operator-(const Vec2& other) { return {x - other.x, y - other.y}; };
        Vec2& operator+=(Vec2& other) { x += other.x; y += other.y; return *this; };
        Vec2& operator-=(Vec2& other) { x -= other.x; y -= other.y; return *this; };
        bool operator==(const Vec2& other) const { return (other.x == x and other.y == y); };
        bool operator!=(const Vec2& other) const { return !this->operator==(other); };
        int x;
        int y;
    };


    class CursesError : public std::runtime_error
    {
    public:
        using std::runtime_error::runtime_error;
    };

    class WideSupportError : public std::logic_error
    {
    public:
        using std::logic_error::logic_error;
    };
}

#endif // _SWEARS_HELPERS_HPP_