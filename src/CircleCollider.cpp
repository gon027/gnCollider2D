#include "../include/CircleCollider.h"
#include "../include/Intersect.h"

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

	
	bool CircleCollider::isHitTest(const CircleCollider &_collider)
	{
		return Intersect::intersect(*this, _collider);
	}

	bool CircleCollider::isHitTest(const BoxCollider& _collider)
	{
		return Intersect::intersect(_collider, *this);
	}

	bool CircleCollider::isHitTest(const LineCollider& _collider){
		return Intersect::intersect(*this, _collider);
	}

	bool CircleCollider::isHitTest(const PointCollider& _collider){
		return Intersect::intersect(*this, _collider);
	}

	bool CircleCollider::isHitTest(const PolygonCollider& _collider)
	{
		return Intersect::intersect(*this, _collider);
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