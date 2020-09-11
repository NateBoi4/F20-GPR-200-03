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
#include "gpro/define_inf.h"

#include "gpro/pixel_color.h"
#include "gpro/hittable_list.h"
#include "gpro/sphere.h"

#include <iostream>
/*
Tests if rays are hitting a hittable surface
Takes in a ray to set the color of the gradient background
Does a white and blue background
Has both a horizontal and vertical gradient
Uses a lerp to blend the colors
*/
color ray_color(const ray& r, const hittable& world) {
    hit_record rec;
    if (world.hit(r, 0, infinity, rec)) {
        return 0.5 * (rec.normal + color(1, 1, 1));
    }
    vect3 unit_direction = unit_vector(r.direction());
    double t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

void image() {

    // Image details and aspects are set

    const double aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    // World

    hittable_list world;
    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

    // Camera from which rays will originate

    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0; //Deistance bewteen projection plane and projection point

    point3 origin = point3(0, 0, 0);
    vect3 horizontal = vect3(viewport_width, 0, 0);
    vect3 vertical = vect3(0, viewport_height, 0);
    vect3 lower_left_corner = origin - horizontal / 2 - vertical / 2 - vect3(0, 0, focal_length);

    /*
    Rendering of image is accomplished here
    The image is rendered by writing out each pixel to the console after its color has been set
    The nested for loops work with the built in image details set earlier in the code
    A progress indicator is used to track the time the rendering takes and to notify the user when the render is completed
    A ray is created to trace the pixels of the image being rendered
    */

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            double u = double(i) / (image_width - 1);
            double v = double(j) / (image_height - 1);
            ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            color pixel_color = ray_color(r, world);
            write_color(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";
}