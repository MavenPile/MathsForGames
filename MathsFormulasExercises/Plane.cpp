#include "Plane.h"

Plane::Plane()
{
	m_a = 0.0f;

	m_b = 0.0f;

	m_c = 0.0f;

	m_d = 0.0f;
}

Plane::Plane(float a, float b, float c, float d)
{
	m_a = a;

	m_b = b;

	m_c = c;

	m_d = d;
}

Plane::~Plane()
{
}

float Plane::GetA()
{
	return m_a;
}

float Plane::GetB()
{
	return m_b;
}

float Plane::GetC()
{
	return m_c;
}

float Plane::GetD()
{
	return m_d;
}
