#pragma once 

#include "boid.h"
#include "utilities.h"
#include "physics.h"

#include <iostream>

// force de cohésion

vec2<int> f_cohesion(boids boidz, boid& b) {
	vec2<int> sum = vec2<int>();
	for (int i = 0; i < boidz.nombre; i++) {
		sum = sum + boidz.vec[i].pos;
	}
	return sum / boidz.nombre - b.pos;
}

// force de séparation 

vec2<int> f_separation(boids boidz, boid& b) {
	vec2<int> sum = vec2<int>();
	for (int i = 0; i < boidz.nombre; i++) {
		sum = sum + (boidz.vec[i].pos - b.pos);
	}
	return sum / (-boidz.nombre); // on prend l'opposée pour bien avoir répulsion
}

// règle d'alignement 

vec2<int> f_alignement(boids boidz, boid& b) {
	vec2<int> sum = vec2<int>();
	for (int i = 0; i < boidz.nombre; i++) {
		sum = sum + boidz.vec[i].vit;
	}
	return sum / boidz.nombre;
}	

//coefficients de pondération 

float c_cohesion = 0.1;
float c_separation = 0;
float c_alignement = 0;

// PFD

vec2<int> acc_pfd(boids& boidz, boid& b) { // masse unitaire
	return c_cohesion * f_cohesion(boidz, b) + c_separation * f_separation(boidz, b) + c_alignement * f_alignement(boidz, b);
}

boids next_boids(boids boidz) {
	boids new_boidz = boidz;
	for (int i = 0; i < boidz.nombre; i++) {
		new_boidz.vec[i].pos = boidz.vec[i].pos + boidz.vec[i].vit;
		new_boidz.vec[i].vit = boidz.vec[i].vit + boidz.vec[i].acc;
		new_boidz.vec[i].acc = acc_pfd(boidz, boidz.vec[i]);
	}
	return new_boidz;
}




