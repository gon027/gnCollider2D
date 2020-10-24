#include "../include/PointCollider.h"
#include "../include/Intersect.h"

namespace gnCollider2D {

	PointCollider::PointCollider()
		: position(Vector2::Zero)
	{
	}

	PointCollider::PointCollider(const Vector2& _pos)
		: position(_pos)
	{
	}

	ColliderType PointCollider::getType()
	{
		return ColliderType::POINT;
	}

	bool PointCollider::isHitTest(const BoxCollider& _collider)
	{
		return Intersect::intersect(_collider, *this);
	}

	bool PointCollider::isHitTest(const CircleCollider& _collider)
	{
		return Intersect::intersect(_collider, *this);
	}

	bool PointCollider::isHitTest(const LineCollider& _collider){
		return Intersect::intersect(_collider, *this);
	}

	bool PointCollider::isHitTest(const PointCollider& _collider)
	{
		auto pos = _collider.position;

		if (position == pos) {
			return true;
		}

		return false;

		//return Intersect::intersect(*this, _collider);
	}

	bool PointCollider::isHitTest(const PolygonCollider& _collider){
		return Intersect::intersect(*this, _collider);
	}

	void PointCollider::update(const Vector2 _pos)
	{
		position = _pos;
	}

	const Vector2& PointCollider::getPos() const
	{
		return position;
	}

}