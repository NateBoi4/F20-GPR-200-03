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
Creates a sphere with surfaces to be hit by the ray and outputed to the console
*/
#ifndef SPHERE_H
#define SPHERE_H

#include "gpro/hittable_surface.h"
#include "gpro/vector_three.h"

/*
Sphere class to set up generating a sphere in the image
*/
class sphere : public hittable {
public:
    sphere() {}
    sphere(point3 cen, double r) : center(cen), radius(r) {};

    virtual bool hit(
        const ray& r, double tmin, double tmax, hit_record& rec) const override;

public:
    point3 center;
    double radius;
};

/*
Gets surface normal to allow for shading
This happens by setting components to an interval from 0 to 1
And setting the x/y/z coordinates to r/g/b values
Surface is made to be front facing, or toward the viewer
*/
bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    vect3 oc = r.origin() - center;
    double a = r.direction().length_squared();
    double half_b = dot(oc, r.direction());
    double c = oc.length_squared() - radius * radius;
    double discriminant = half_b * half_b - a * c;

    if (discriminant > 0) {
        double root = sqrt(discriminant);

        double temp = (-half_b - root) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.at(rec.t);
            vect3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);
            return true;
        }

        temp = (-half_b + root) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.at(rec.t);
            vect3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);
            return true;
        }
    }

    return false;
}


#endif