#include "../include/CircleCollider.h"

namespace gnCollider {

	CircleCollider::CircleCollider()
		: position(Vector2::Zero)
		, radius(Vector2::Zero)
	{
	}

	CircleCollider::CircleCollider(const Vector2& _vector, const Vector2& _radius)
		: position(_vector)
		, radius(_radius)
	{
	}

	CircleCollider::CircleCollider(float _x, float _y, float _rx, float _ry)
		: position(Vector2{ _x, _y })
		, radius(Vector2{ _rx, _ry })
	{

	}

	void CircleCollider::update(const Vector2& _vector, const Vector2& _radius)
	{
		position.setPos(_vector);
		radius.setPos(_radius);
	}

	bool CircleCollider::isHitTest(const CircleCollider& _circleCollider)
	{
		auto dist = _circleCollider.position - this->position;
		auto c = dist.magnitude();
		auto r = _circleCollider.radius + this->radius;

		if (c <= r.x * r.x) {
			return true;
		}

		return false;
	}

	bool CircleCollider::isHitTest(const BoxCollider& _collider)
	{
		return false;
	}

	bool CircleCollider::isHitTest(const PolygonCollider& _collider)
	{
		return false;
	}

	ColliderType CircleCollider::getType()
	{
		return ColliderType::CIRCLE;
	}

	Vector2& CircleCollider::getPos()
	{
		return position;
	}

	Vector2& CircleCollider::getRadius()
	{
		return radius;
	}


}