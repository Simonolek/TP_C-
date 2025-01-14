#pragma once

#include <iostream>
#include <random>
#include <ctime>

struct float2 { // vecteur de taille 2
	float x;
	float y;

	float2 operator+(float2 const& obj) {
		float2 res;
		res.x = x + obj.x;
		res.y = y + obj.y;
		return res;
	}

	float2 operator-(float2 const& obj) {
		float2 res;
		res.x = x - obj.x;
		res.y = y - obj.y;
		return res;
	}

	float2 operator/(int const i) {
		float2 res;
		res.x = x / i;
		res.y = y / i;
		return res;
	}
};

float2 operator*(float2 const vec, float const i) {
	float2 res;
	res.x = vec.x * i;
	res.y = vec.y * i;
	return res;
}

float2 operator*(float const i, float2 const vec) {
	float2 res;
	res = vec * i;
	return res;
}


float randf() { // renvoie un flottant aléatoire
	return (float)(rand()) / (float)(rand());
}

float2 randvec2f() { // renvoie un vecteur de taille 2 aléatoire
	return { randf(), randf() };
}