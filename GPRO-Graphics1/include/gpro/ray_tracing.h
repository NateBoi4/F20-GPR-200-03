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
Defines what a ray is and generates the formula for creating a ray
*/
#ifndef RAY_TRACING_H
#define RAY_TRACING_H

#include "gpro/vector_three.h"

/*
Implementation of ray class for ray tracing
Sets up the necessary elements of the ray function
Function requires the ray's origin, the ray's direction, and a number to be passed through
*/
class ray {
public:
    ray() {}
    ray(const point3& origin, const vect3& direction)
        : orig(origin), dir(direction)
    {}

    point3 origin() const { return orig; }
    vect3 direction() const { return dir; }

    point3 at(double t) const {
        return orig + t * dir;
    }

public:
    point3 orig;
    vect3 dir;
};

#endif
