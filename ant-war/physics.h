#ifndef __PHYSICS_H__
#define __PHYSICS_H__


#pragma once 

#include "boid.h"
#include "utilities.h"


// force de coh�sion

vec2<int> f_cohesion(boids boidz, boid& b);

// force de s�paration 

vec2<int> f_separation(boids boidz, boid& b);

// r�gle d'alignement 

vec2<int> f_alignement(boids boidz, boid& b);

// PFD

vec2<int> acc_pfd(boids& boidz, boid& b);

boids next_boids(boids boidz);


#endif

