#pragma once

class Point
{
private:

	float m_x;

	float m_y;

	float m_z;

public:

	Point();

	Point(float x, float y);

	Point(float x, float y, float z);

	~Point();

	float GetX();

	float GetY();

	float GetZ();
};

