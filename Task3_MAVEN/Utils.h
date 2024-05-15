#pragma once

//	DEFINITIONS

#define pi 3.1415f;

#define Rad2Deg 180.f / pi

#define Deg2Rad pi / 180.f

//	FLT UTILS

constexpr float Minf(float a, float b) { return a < b ? a : b; }

constexpr float Maxf(float a, float b) { return a > b ? a : b; }

constexpr float Clampf(float t, float a, float b) { return Maxf(a, Minf(b, t)); }
