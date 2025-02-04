#ifndef __BOID_H__
#define __BOID_H__

#include <vector>

#include "utilities.h"

struct entity {
	vec2<int> pos;
	vec2<int> vit;

	entity();
	entity(vec2<int> p, vec2<int> v);

	virtual ~entity() = default;
};


struct boid : public virtual entity {
	vec2<int> acc;

	boid();
};

struct boids {
	std::vector<boid> vec;
	int nombre;

	boids(int entier);
};


#endif