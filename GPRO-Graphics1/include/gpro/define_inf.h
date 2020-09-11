#ifndef DEFINE_INF_H
#define DEFINE_INF_H

#include <cmath>
#include <cstdlib>
#include <limits>
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
Gives definition to missing math constants and adds math utility functions
*/
#include <memory>


// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants

/*
Adds a definition for infinity
Infinity is used for detecting hits
Adds a definition for pi
Allows for conversion from degrees to radians, which is useful when wokring with spheres
*/
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

// Common Headers

#include "ray_tracing.h"
#include "gpro-math/gproVector.h"

#endif