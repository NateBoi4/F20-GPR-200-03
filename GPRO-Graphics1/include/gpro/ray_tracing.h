#ifndef RAY_TRACING_H
#define RAY_TRACING_H

#include "gpro/vector_three.h"

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
