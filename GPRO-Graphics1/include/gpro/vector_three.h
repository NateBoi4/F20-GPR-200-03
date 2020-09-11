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
#ifndef VECTOR_THREE_H
#define VECTOR_THREE_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vect3 {
public:
    vect3() : e{ 0,0,0 } {} //Default vector constructor
    vect3(double e0, double e1, double e2) : e{ e0, e1, e2 } {} //Constructor for a vector object

    double x() const { return e[0]; } //x - coordinate of a point vector
    double y() const { return e[1]; } //y - coordinate of a point vector
    double z() const { return e[2]; } //z - coordinate of a point vector

    vect3 operator-() const { return vect3(-e[0], -e[1], -e[2]); } //Returns negative values back the original vector
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    //Adds the values of the elements of two vectors
    vect3& operator+=(const vect3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    //Multiplies the values of the elements of a vector by a double passed through the parameter
    vect3& operator*=(const double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    //Divides the values of the elements of a vector by a double passed through the parameter
    vect3& operator/=(const double t) {
        return *this *= 1 / t;
    }

    //Takes the square root of the values in a vector
    double length() const {
        return sqrt(length_squared());
    }

    //Multiplies the values in a vector by themselves and then adds them together
    double length_squared() const {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }

public:
    double e[3];
};

// Type aliases for vect3
using point3 = vect3;   // 3D point
using color = vect3;    // RGB color

// vect3 Utility Functions

//Outputs the elements of a vector to the output stream
inline std::ostream& operator<<(std::ostream& out, const vect3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

//Adds the values of the elements of two vectors
inline vect3 operator+(const vect3& u, const vect3& v) {
    return vect3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

//Subtracts the values of the elements of two vectors
inline vect3 operator-(const vect3& u, const vect3& v) {
    return vect3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

//Multiplies the values of the elements of two vectors
inline vect3 operator*(const vect3& u, const vect3& v) {
    return vect3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

//Multiplies the values of the elements of a vector by a double passed through the parameter
inline vect3 operator*(double t, const vect3& v) {
    return vect3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

//Multiplies the vector by a double
inline vect3 operator*(const vect3& v, double t) {
    return t * v;
}

//Divides the values of the elements of a vector by a double passed through the parameter
inline vect3 operator/(vect3 v, double t) {
    return (1 / t) * v;
}

//Gets the dot product of two vectors passed through
inline double dot(const vect3& u, const vect3& v) {
    return u.e[0] * v.e[0]
        + u.e[1] * v.e[1]
        + u.e[2] * v.e[2];
}

//Gets the cross product of two vectors passed through
inline vect3 cross(const vect3& u, const vect3& v) {
    return vect3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
        u.e[2] * v.e[0] - u.e[0] * v.e[2],
        u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

//Gets the unit vector of a vector passed through
inline vect3 unit_vector(vect3 v) {
    return v / v.length();
}

#endif

