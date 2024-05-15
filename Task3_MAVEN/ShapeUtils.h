#pragma once

#include "Vector3.h"
#include "Matrix3.h"
#include <vector>

#define pi 3.14159265359f;

//#define Rad2Deg (180.f / pi)
//
//#define Deg2Rad (pi / 180.f)

constexpr float Min(float a, float b)
{
	return a < b ? a : b;
}

constexpr float Max(float a, float b)
{
	return a > b ? a : b;
}

Math::Vector3 Min(const Math::Vector3& a, const Math::Vector3 b)
{
	return { Min(a.x,b.x),Min(a.y,b.y), 1 };
}

Math::Vector3 Max(const Math::Vector3& a, const Math::Vector3 b)
{
	return { Max(a.x,b.x),Max(a.y,b.y), 1 };
}

constexpr float clamp(float t, float a, float b)
{
	return Max(a, Min(b, t));
}

Math::Vector3 clamp(const Math::Vector3& t, const Math::Vector3& a, const Math::Vector3& b)
{
	return Max(a, Min(b, t));
}