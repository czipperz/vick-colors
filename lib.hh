/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef HEADER_GUARD_VICK_COLORS_H
#define HEADER_GUARD_VICK_COLORS_H

#include <vector>

namespace vick {
namespace colors {

/*!
 * \file vick-colors/lib.hh
 * \brief Allow the user to interact with the coloring text on the
 * screen safely.
 */

/*! \brief A typedef for RGB values [0, 255] */
using color_type = short;

/*!
 * \brief Represents a color with each value from [0, 255]
 */
struct color {
public:
    /*!
     * \brief Construct a derived color with its representation in
     * ncurses the same as the derived color.
     */
    color(color_type r, color_type g, color_type b,
          const color&);

    /*!
     * \brief Construct a color that will be displayed as the default
     * color in ncurses (no highlighting).
     */
    color();

public:
    /* By making these mutable and the default colors const, it allows
     * modification of the color values for */
    mutable color_type r /*!< \brief Red value of the color. */;
    mutable color_type g /*!< \brief Green value of the color. */;
    mutable color_type b /*!< \brief Blue value of the color. */;

    /*!
     * \brief The internal identifier for ncurses interaction.
     *
     * Only mutable for non default colors.
     */
    int ncurses_internal_representation;

    static const color black;
    static const color blue;
    static const color cyan;
    static const color green;
    static const color magenta;
    static const color red;
    static const color white;
    static const color yellow;

    static const color no_color;

private:
    color(color_type r, color_type g, color_type b,
          int ncurses_internal_representation);
};

/*!
 * \brief Export color's static variables so people can use colors as
 * `vick::colors::black` instead of `vick::colors::color::black`
 */
namespace {
const color& black    = color::black;
const color& blue     = color::blue;
const color& cyan     = color::cyan;
const color& green    = color::green;
const color& magenta  = color::magenta;
const color& red      = color::red;
const color& white    = color::white;
const color& yellow   = color::yellow;

const color& no_color = color::yellow;
}

struct pair {
    const color& foreground;
    const color& background;
};
}
}

#endif
