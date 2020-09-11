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
*/
#ifndef HITTABLE_SURFACE_H
#define HITTABLE_SURFACE_H

#include "gpro/ray_tracing.h"

/*
Hit function takes in a ray to determine whether something is "hittable" or not by the ray
Also determines which side the ray is on when coloring
*/
struct hit_record {
    point3 p;
    vect3 normal;
    double t;
    bool front_face;

    inline void set_face_normal(const ray& r, const vect3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable {
public:
    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif