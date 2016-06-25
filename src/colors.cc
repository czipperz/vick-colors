#include "../lib.hh"

namespace vick {
namespace colors {
color::color(color_type r, color_type g, color_type b, int n)
    : r(r)
    , g(g)
    , b(b)
    , ncurses_internal_representation(n) {}

color::color(color_type r, color_type g, color_type b,
             const color& c)
    : color(r, g, b, c.ncurses_internal_representation) {}

color::color()
    : color(0, 0, 0, -1) {}

const color color::black   = {0,   0,   0,   0};
const color color::blue    = {0,   0,   255, 4};
const color color::cyan    = {0,   255, 255, 6};
const color color::green   = {0,   255, 0,   2};
const color color::magenta = {255, 0,   255, 5};
const color color::red     = {255, 0,   0,   1};
const color color::white   = {255, 255, 255, 7};
const color color::yellow  = {255, 255, 51,  3};
}
}
