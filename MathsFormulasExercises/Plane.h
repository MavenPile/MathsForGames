#pragma once

class Plane
{
private:

	float m_a;

	float m_b;

	float m_c;

	float m_d;

public:

	Plane();

	Plane(float a, float b, float c, float d);

	~Plane();

	float GetA();
	
	float GetB();

	float GetC();

	float GetD();
};

