#include "Point.h"

Point::Point()
{
	m_x = 0.0f;

	m_y = 0.0f;

	m_z = 0.0f;
}

Point::Point(float x, float y)
{
	m_x = x;

	m_y = y;

	m_z = 0.0f;
}

Point::Point(float x, float y, float z)
{
	m_x = x;

	m_y = y;

	m_z = z;
}

Point::~Point()
{
}

float Point::GetX()
{
	return m_x;
}

float Point::GetY()
{
	return m_y;
}

float Point::GetZ()
{
	return m_z;
}
