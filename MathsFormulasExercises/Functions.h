#pragma once
#include "Point.h"
#include "Plane.h"

float Quadratic(float x, float c);

bool QuadFormula(float a, float b, float c);

float Lerp(float s, float e, float t);

float Pythag(Point P1, Point P2);

float Dot(Point P, Point Q);

float PlanePointDist(Plane P, Point p);

float CubicBezier(float t, float P0, float P1, float P2, float P3);