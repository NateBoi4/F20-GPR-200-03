#include "gpro-math/gproVector.h"


class rt {
public:
    rt() {}
    rt(const vec3& origin, const vec3& direction)
        : orig(origin), dir(direction)
    {}

    vec3 origin() const { return orig; }
    vec3 direction() const { return dir; }

    vec3 at(double t) const {
        return orig + t * dir;
    }

public:
    vec3 orig;
    vec3 dir;
};
