#pragma once 

#include "boid.h"
#include "utilities.h"

int n; // nombre de 
std::vector<boid> boids;

// initialisation des boids

void setup(int number) {
	n = number;
	for (int i = 0; i < n; i++) {
		boid b;
		boids.push_back(b);
	}
}

// force de cohésion

float2 f_cohesion(boid b) {
	float2 sum = { 0.0, 0.0};
	for (int i = 0; i < n; i++) {
		sum = sum + boids[i].pos;
	}
	return sum / n - b.pos;
}

// force de séparation 

float2 f_separation(boid b) {
	float2 sum = { 0.0, 0.0 };
	for (int i = 0; i < n; i++) {
		sum = sum + (boids[i].pos - b.pos);
	}
	return sum / (- n); // on prend l'opposée pour bien avoir répulsion
}

// règle d'alignement 

float2 f_alignement(boid b) {
	float2 sum = { 0.0, 0.0 };
	for (int i = 0; i < n; i++) {
		sum = sum + boids[i].vit;
	}
	return sum / n;
}

//coefficients de pondération 

float c_cohesion = 1.0;
float c_separation = 1.0;
float c_alignement = 1.0;

// PFD

float2 acc_pfd(boid b) { // masse unitaire 
	return c_cohesion * f_cohesion(b) + c_separation * f_separation(b) + c_alignement * f_alignement(b);
}

void next_boids() {
	for (int i = 0; i < n; i++) {
		boids[i].pos = boids[i].pos + boids[i].vit;
		boids[i].vit = boids[i].vit + boids[i].acc;
		boids[i].acc = acc_pfd(boids[i]);
	}
}




