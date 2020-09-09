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

#include "gpro/gpro-math/gproVector.h"
#include "gpro/image.h"

void image() {
	//Image Details

	const int width = 400; //Image width
	const int height = 644; //Image height

	//Create Image by writing to file
    cout << "P3\n" << width << ' ' << height << "\n255\n"; 
    //P3 for ASCII colors, image width, image height, and 255 is max color on the rgb scale, 0 to 255

    float3 colors; //Create float vector named colors

    /*
    Using a for loop and a nested for loop, this code creates the image by writing to the program output.
    It writes in terms a vec3 which determines the colors of each row of pixels.
    It moves across the rows then down the columns as it writes each color of the image
    The program ends by informing the user the process is complete by writing to the error log.
    */
    for (double i = height - 1.0; i >= 0; --i) {
        for (double j = 0; j < width; ++j) {
            vec3init(colors, float((j / (width - 1.0))), float((i / (height - 1.0))), float(0.5));

            int r = static_cast<int>(255.999 * colors[0]);
            int g = static_cast<int>(255.999 * colors[1]);
            int b = static_cast<int>(255.999 * colors[2]);

            cout << r << ' ' << g << ' ' << b << '\n';
        }
    }
    cerr << "Done\n";
}