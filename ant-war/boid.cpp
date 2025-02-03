#pragma once


#include <iostream>
#include <vector>

#include "utilities.h"
#include "boid.h"



boid::boid() {
	pos = randvec2f();
	vit = randvec2f();
	acc = float2(); // acceleration initialement nulle
}

boids::boids(int entier) {
	nombre = entier;
	for (int i = 0; i < nombre; i++) {
		boid b;
		vec.push_back(b);
	}
}



