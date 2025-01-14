#pragma once

#include "utilities.h"

#include <iostream>
#include <vector>

struct boid {
	float2 pos;
	float2 vit;
	float2 acc;

	boid() {
		pos = randvec2f();
		vit = randvec2f();
		acc = { 0.0, 0.0 };
	}
};

