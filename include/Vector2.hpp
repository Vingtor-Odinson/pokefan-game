#ifndef __VECTOR2__
#define __VECTOR2__

#include <math.h>

class Vector2{

private:

	float m_x;
	float m_y;

public:


	Vector2(float x, float y): m_x(x), m_y(y) {}

	float getX() const {return m_x;}

	float getY() const {return m_y;}

	void setX(float x){m_x = x;}

	void setY(float y){m_y = y;}

	float len() const {return sqrt(m_x*m_x + m_y*m_y);}

	const Vector2 operator+(const Vector2& vec2) const
	{
		return Vector2(m_x + vec2.getX(), m_y + vec2.getY());
	}

	friend Vector2& operator+=(Vector2& v1, const Vector2& v2)
	{
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;

		return v1;
	}

	Vector2 operator-(const Vector2& vec2) const
	{
		return Vector2(m_x - vec2.getX(), m_y - vec2.getY());
	}

	friend Vector2& operator-=(Vector2& v1, const Vector2& v2)
	{
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;

		return v1;
	}

	Vector2 operator*(float alpha){
		return Vector2(m_x*alpha, m_y*alpha);
	}

	Vector2& operator*=(float alpha)
	{
		m_x *= alpha;
		m_y *= alpha;
	
		return *this;
	}

	Vector2 operator/(float alpha){
		return Vector2(m_x/alpha, m_y/alpha);
	}

	Vector2& operator/=(float alpha)
	{
		if(alpha != 0)
		{
			m_x /= alpha;
			m_y /= alpha;
		}
		
		return *this;
	}

	Vector2 Normalize()
	{
		return Vector2(m_x/this->len(), m_y/this->len());
	}

};



#endif