#include "Functions.h"
#include <ctgmath>
#include <cmath>

float Quadratic(float x, float c)
{
	return (x * x) + (2 * x) - c;
}

bool QuadFormula(float a, float b, float c)
{
	if (((b * b) - (4 * a * c)) < 0)
	{
		return false;	//	no roots
	}

	return true;
}

float Lerp(float s, float e, float t)
{
	return s + (e - s) * t;
}

float Pythag(Point P1, Point P2)
{
	float inner = (P1.GetX() - P2.GetX()) * (P1.GetX() - P2.GetX()) + (P1.GetY() - P2.GetY()) * (P1.GetY() - P2.GetY());
	
	if (inner < 0)
	{
		return 0.0f;	//	prevent square rooting negative numbers
	}

	return sqrt(inner);
}

float Dot(Point P, Point Q)
{
	return P.GetX() * Q.GetX() + P.GetY() * Q.GetY() + P.GetZ() * Q.GetZ();
}

float PlanePointDist(Plane P, Point p)
{
	float top = P.GetA() * p.GetX() + P.GetB() * p.GetY() + P.GetC() * p.GetZ();

	float bottom = P.GetA() * P.GetA() + P.GetB() * P.GetB() + P.GetC() * P.GetC();

	if (bottom < 0)
	{
		return 0.0f;	//	prevent square rooting negative numbers
	}

	bottom = sqrt(bottom);
	
	return top / bottom;
}

float CubicBezier(float t, float P0, float P1, float P2, float P3)
{
	float term1 = (1 - t) * (1 - t) * (1 - t) * P0;

	float term2 = 3 * (1 - t) * (1 - t) * t * P1;

	float term3 = 3 * (1 - t) * t * t * P2;

	float term4 = t * t * t * P3;
	
	return term1 + term2 + term3 + term4;
}
