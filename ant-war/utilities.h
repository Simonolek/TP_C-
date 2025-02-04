#ifndef __UTILITIES_H__
#define __UTILITIES_H__

#include <stdexcept>

template <typename T>
struct vec2 {
	T x;
	T y;

	vec2() : x(0), y(0) {};
	vec2(T x_, T y_) : x(x_), y(y_) {};

	vec2 operator+(const vec2& obj) {
		return vec2(x + obj.x, y + obj.y);
	}

	vec2 operator-(const vec2& obj) {
		return vec2(x - obj.x, y - obj.y);
	}

	vec2 operator/(T i) {
		if (i == 0) {
			throw std::runtime_error("Erreur : division par 0 !");
		}
		return vec2(x / i, y / i);
	}
	
	vec2 operator*(T i) {
		return vec2(x * i, y * i);
	}

	friend vec2 operator*(T i, const vec2& vec) {
		return vec2(vec.x * i, vec.y * i);
	}
};

int randomint(int min, int max);

template <typename T>
vec2<T> randvec2(T max1, T max2) {
	return vec2<T>(randomint(0, max1), randomint(0, max2));
}

#endif