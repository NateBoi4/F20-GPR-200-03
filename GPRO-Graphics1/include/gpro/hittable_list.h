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
#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "gpro/hittable_surface.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;


/*
Class that stores a list of hittables
Uses hittable to determine what is and isn't a hittable surface
Takes in an object and compares its surface to what should and should not be hittable
Makes use of shared pointers for better memory management and to allow multiple objects 
to have common instances that can be compared and contrasted. Is essentially a collection of pointers
Vector is used to create an array to hold the collection of pointers
*/
class hittable_list : public hittable {
public:
    hittable_list() {}
    hittable_list(shared_ptr<hittable> object) { add(object); }

    void clear() { objects.clear(); }
    void add(shared_ptr<hittable> object) { objects.push_back(object); }

    virtual bool hit(
        const ray& r, double tmin, double tmax, hit_record& rec) const override;

public:
    std::vector<shared_ptr<hittable>> objects;
};

bool hittable_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    hit_record temp_rec;
    bool hit_anything = false;
    double closest_so_far = t_max;

    for (int i = 0; i < objects.size(); i++) {
        if (objects[i]->hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}

#endif
