#ifndef VECTOR_THREE_H
#define VECTOR_THREE_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vect3 {
public:
    vect3() : e{ 0,0,0 } {}
    vect3(double e0, double e1, double e2) : e{ e0, e1, e2 } {}

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    vect3 operator-() const { return vect3(-e[0], -e[1], -e[2]); }
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    vect3& operator+=(const vect3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    vect3& operator*=(const double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    vect3& operator/=(const double t) {
        return *this *= 1 / t;
    }

    double length() const {
        return sqrt(length_squared());
    }

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

inline std::ostream& operator<<(std::ostream& out, const vect3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vect3 operator+(const vect3& u, const vect3& v) {
    return vect3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vect3 operator-(const vect3& u, const vect3& v) {
    return vect3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vect3 operator*(const vect3& u, const vect3& v) {
    return vect3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vect3 operator*(double t, const vect3& v) {
    return vect3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vect3 operator*(const vect3& v, double t) {
    return t * v;
}

inline vect3 operator/(vect3 v, double t) {
    return (1 / t) * v;
}

inline double dot(const vect3& u, const vect3& v) {
    return u.e[0] * v.e[0]
        + u.e[1] * v.e[1]
        + u.e[2] * v.e[2];
}

inline vect3 cross(const vect3& u, const vect3& v) {
    return vect3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
        u.e[2] * v.e[0] - u.e[0] * v.e[2],
        u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vect3 unit_vector(vect3 v) {
    return v / v.length();
}

#endif

