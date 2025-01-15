#ifndef __UTILITIES_H__
#define __UTILITIES_H__
 
struct float2 {
	float x;
	float y;

	float2();

	float2 operator+(float2 const& obj);
	float2 operator-(float2 const& obj);
	float2 operator/(int const i);

};

float2 operator*(float2 const vec, float const i);
float2 operator*(float const i, float2 const vec);

float randf();
float2 randvec2f();

#endif