#ifndef __PHYSICS_H__
#define __PHYSICS_H__


#pragma once 

#include "boid.h"
#include "utilities.h"


// force de cohésion

float2 f_cohesion(boids boidz, boid& b);

// force de séparation 

float2 f_separation(boids boidz, boid& b);

// règle d'alignement 

float2 f_alignement(boids boidz, boid& b);

// PFD

float2 acc_pfd(boids& boidz, boid& b);

boids next_boids(boids boidz);


#endif

