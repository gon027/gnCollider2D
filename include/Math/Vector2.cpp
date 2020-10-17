#include "Vector2.h"
#include <cmath>

namespace gnCollider2D {
	Vector2 Vector2::Up     {  0.0f,  1.0f };
	Vector2 Vector2::Down   {  0.0f, -1.0f };
	Vector2 Vector2::Left   { -1.0f,  0.0f };
	Vector2 Vector2::Right  {  1.0f,  0.0f };
	Vector2 Vector2::One    {  1.0f,  1.0f };
	Vector2 Vector2::Zero   {  0.0f,  0.0f };

	Vector2::Vector2()
		: x(0)
		, y(0)
	{ }

	Vector2::Vector2(const Vector2 & _vector)
		: x(_vector.x)
		, y(_vector.y)	
	{ }

	Vector2::Vector2(float _x, float _y)
		: x(_x)
		, y(_y)
	{ }

	Vector2::Vector2(float _xy)
		: x(_xy)
		, y(_xy)
	{ }

	void Vector2::setPos(float _x, float _y)
	{
		x = _x;
		y = _y;
	}

	void Vector2::setPos(const Vector2 & _vector)
	{
		x = _vector.x;
		y = _vector.y;
	}

	const float Vector2::magnitude() const
	{
		return x * x + y * y;
	}

	const Vector2 Vector2::normalized() const
	{
		auto length = sqrMagnitude();

		if (length != 0) {
			return { x / length, y / length };
		}
		else {
			return *this;
		}
	}

	const float Vector2::sqrMagnitude() const
	{
		return std::sqrt(magnitude());
	}

	const Vector2 Vector2::half() const
	{
		return Vector2{ x / 2.0f, y / 2.0f };
	}

	const float Vector2::dot(const Vector2& _rvec)
	{
		return this->x * _rvec.x + this->y * _rvec.y;
	}

	const float Vector2::cross(const Vector2 & _rvec)
	{
		return this->x * _rvec.y - this->y * _rvec.x;
	}

	const Vector2 Vector2::operator+() const
	{
		return {x, y};
	}

	const Vector2 Vector2::operator-() const
	{
		return {-x, -y};
	}

	const Vector2 Vector2::operator+(const Vector2 & _rvec) const
	{
		return {x + _rvec.x, y + _rvec.y};
	}

	const Vector2 Vector2::operator-(const Vector2 & _rvec) const
	{
		return { x - _rvec.x, y - _rvec.y };
	}

	const Vector2 Vector2::operator*(const Vector2 & _rvec) const
	{
		return { x * _rvec.x, y * _rvec.y };
	}

	const Vector2 Vector2::operator/(const Vector2 & _rvec) const
	{
		return { x / _rvec.x, y / _rvec.y };
	}

	const Vector2& Vector2::operator+=(const Vector2 & _rvec)
	{
		this->x += _rvec.x;
		this->y += _rvec.y;
		return *this;
	}

	const Vector2& Vector2::operator-=(const Vector2 & _rvec)
	{
		this->x -= _rvec.x;
		this->y -= _rvec.y;
		return *this;
	}

	const Vector2& Vector2::operator*=(const Vector2 & _rvec)
	{
		this->x *= _rvec.x;
		this->y *= _rvec.y;
		return *this;
	}

	const Vector2& Vector2::operator/=(const Vector2 & _rvec)
	{
		this->x /= _rvec.x;
		this->y /= _rvec.y;
		return *this; Vector2();
	}

	const bool Vector2::operator==(const Vector2 & _rvec) const
	{
		return (x == _rvec.x) && (y == _rvec.y);
	}

	const bool Vector2::operator!=(const Vector2 & _rvec) const
	{
		return (x != _rvec.x) || (y != _rvec.y);
	}
}
