#pragma once


#include <iostream>
#include <vector>

#include "utilities.h"
#include "boid.h"



entity::entity() : pos(0, 0), vit(0, 0) {}
entity::entity(vec2<int> p, vec2<int> v) : pos(p), vit(v) {}

boid::boid() : entity(randvec2<int>(800, 600), randvec2<int>(10, 10)), acc() {}

boids::boids(int entier) {
	nombre = entier;
	for (int i = 0; i < nombre; i++) {
		boid b;
		vec.push_back(b);
	}
}



