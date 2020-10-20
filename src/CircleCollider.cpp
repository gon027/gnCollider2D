#include "../include/CircleCollider.h"
#include "../include/BoxCollider.h"
#include "../include/LineCollider.h"
#include "../include/PointCollider.h"
#include "../include/PolygonCollider.h"
#include "../include/Math/Math.h"

namespace gnCollider2D {

	CircleCollider::CircleCollider()
		: position(Vector2::Zero)
		, radius(0.0f)
	{
	}

	CircleCollider::CircleCollider(const Vector2& _vector, float _radius)
		: position(_vector)
		, radius(_radius)
	{
	}

	CircleCollider::CircleCollider(float _x, float _y, float _r)
		: position(Vector2{ _x, _y })
		, radius(_r)
	{

	}

	ColliderType CircleCollider::getType()
	{
		return ColliderType::CIRCLE;
	}

	bool CircleCollider::isHitTest(const CircleCollider& _circleCollider)
	{
		auto dist = _circleCollider.position - position;
		auto c = dist.magnitude();
		auto r = _circleCollider.radius + this->radius;

		if (c <= r * r)
		{
			return true;
		}

		return false;
	}

	bool CircleCollider::isHitTest(const BoxCollider& _collider)
	{
		auto& b = _collider.getBounds();
		auto& p = position;

		if (p.x > b.minPos.x && p.x < b.maxPos.x && p.y > b.minPos.y - radius && p.y < b.maxPos.y + radius)
		{
			return true;
		}

		if (p.x > b.minPos.x - radius && p.x < b.maxPos.x + radius && p.y > b.minPos.y && p.y < b.maxPos.y)
		{
			return true;
		}

		float r = radius * radius;

		float rx = b.minPos.x - p.x;
		float ry = b.minPos.y - p.y;
		float d = dist(rx, ry);
		if (d < r) return true;

		rx = b.maxPos.x - p.x;
		ry = b.minPos.y - p.y;
		d = dist(rx, ry);
		if (d < r) return true;

		rx = b.maxPos.x - p.x;
		ry = b.maxPos.y - p.y;
		d = dist(rx, ry);
		if (d < r) return true;

		rx = b.minPos.x - p.x;
		ry = b.maxPos.y - p.y;
		d = dist(rx, ry);
		if (d < r) return true;

		return false;

		return false;
	}

	bool CircleCollider::isHitTest(const LineCollider& _collider){
		return false;
	}

	bool CircleCollider::isHitTest(const PointCollider& _collider){
		return false;
	}

	bool CircleCollider::isHitTest(const PolygonCollider& _collider)
	{
		return false;
	}

	void CircleCollider::update(const Vector2& _vector, float _radius)
	{
		position.setPos(_vector);
		radius = _radius;
	}

	const Vector2& CircleCollider::getPos() const
	{
		return position;
	}

	const float CircleCollider::getRadius() const 
	{
		return radius;
	}

}