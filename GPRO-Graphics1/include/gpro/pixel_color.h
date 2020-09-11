/*
Credit to Peter Shirley and his book "Ray Tracing in One Weekend"
Peter Shirley
edited by Steve Hollasch and Trevor David Black

Version 3.2.0, 2020-07-18

Copyright 2018-2020 Peter Shirley. All rights reserved.

Link to book: https://raytracing.github.io/books/RayTracingInOneWeekend.html

Work references Chapter 1: Overview
                Chapter 2: Output an Image
                Chapter 3: The vec3 Class
                Chapter 4: Rays, a Simple Camera, and Background
                Chapter 5: Adding a Sphere
                Chapter 6: Surface Normals and Multiple Objects

Code has been edited by Nathan Boisvert 2020
Small function to simplify writing to each pixel on a screen and coloring it.
*/
#ifndef PIXEL_COLOR_H
#define PIXEL_COLOR_H

#include "gpro/vector_three.h"

#include <iostream>

//Writes the colors of a pixel to the output stream
void write_color(std::ostream& out, color pixel_color) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.x()) << ' ' //The r value
        << static_cast<int>(255.999 * pixel_color.y()) << ' ' //The g value
        << static_cast<int>(255.999 * pixel_color.z()) << '\n'; //The b value
}

#endif
