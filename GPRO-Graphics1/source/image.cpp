/*
Credit to Peter Shirley and his book "Ray Tracing in One Weekend"
Peter Shirley
edited by Steve Hollasch and Trevor David Black

Version 3.2.0, 2020-07-18

Copyright 2018-2020 Peter Shirley. All rights reserved.

Link to book: https://raytracing.github.io/books/RayTracingInOneWeekend.html

Work references Chapter 2: Output an Image
*/

#include <iostream>

using namespace std;

#include "gpro/image.h"

void image() {
	//Image Details

	const int width = 400; //Image width
	const int height = 644; //Image height

	//Create Image
    cout << "P3\n" << width << ' ' << height << "\n255\n";

    for (double i = height - 1; i >= 0; --i) {
        for (double j = 0; j < width; ++j) {
            double r = j / (width - 1);
            double g = i / (height - 1);
            double b = 0.50;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}