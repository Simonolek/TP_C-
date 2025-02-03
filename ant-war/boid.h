#ifndef __BOID_H__
#define __BOID_H__

#include <vector>

#include "utilities.h"

struct boid {
	float2 pos;
	float2 vit;
	float2 acc;

	boid();
};

struct boids {
	std::vector<boid> vec;
	int nombre;

	boids(int entier);
};


#endif