#include "../include/PointCollider.h"
#include "../include/CircleCollider.h"
#include "../include/BoxCollider.h"

namespace gnCollider {

	PointCollider::PointCollider()
		: position(Vector2::Zero)
	{
	}

	PointCollider::PointCollider(const Vector2& _pos)
		: position(_pos)
	{
	}

	PointCollider::~PointCollider()
	{
	}

	ColliderType PointCollider::getType()
	{
		return ColliderType::POINT;
	}

	void PointCollider::update(const Vector2 _pos)
	{
		position = _pos;
	}

	bool PointCollider::isHitTest(const PointCollider& _collider)
	{
		auto pos = _collider.position;

		if (position == pos) {
			return true;
		}

		return false;
	}

	bool PointCollider::isHitTest(const BoxCollider& _collider)
	{
		auto min = _collider.getMin();
		auto max = _collider.getMax();

		if (position.x >= min.x &&
			position.x <= max.x &&
			position.y >= min.y &&
			position.y <= max.y) {
			return true;
		}

		return false;
	}

	bool PointCollider::isHitTest(const CircleCollider& _collider)
	{
		//auto a = p - position;


		//if()

		return false;
	}

	bool PointCollider::isHitTest(const PolygonCollider& _collider)
	{
		return false;
	}

	Vector2& PointCollider::getPos()
	{
		return position;
	}

}