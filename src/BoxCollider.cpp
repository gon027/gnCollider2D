#include "../include/BoxCollider.h"

namespace gnCollider {

	BoxCollider::BoxCollider(Vector2& _pos, Vector2& _min, Vector2& _max)
		: center(_pos)
	{
	}

	bool BoxCollider::isHitTest(BoxCollider& _collider)
	{
		if (getMax().x >= _collider.getMin().x
			&& getMin().x <= _collider.getMax().x
			&& getMax().y >= _collider.getMin().y
			&& getMin().y <= _collider.getMax().y)
		{
			return true;
		}

		return false;
	}

	bool gnCollider::BoxCollider::isHitTest(const CircleCollider& _collider)
	{
		return false;
	}

	bool gnCollider::BoxCollider::isHitTest(const PolygonCollider& _collider)
	{
		return false;
	}

	void BoxCollider::update(const Vector2& _pos, const Bounds& _bounds)
	{
		center.setPos(_pos);
		bounds = _bounds;
		size.setPos(bounds.rightBottom - bounds.leftTop);
	}

	Vector2 BoxCollider::getPos() const
	{
		return center;
	}

	Vector2 BoxCollider::getMin() const
	{
		return bounds.leftTop;
	}

	Vector2 BoxCollider::getMax() const
	{
		return bounds.rightBottom;
	}

	Vector2 BoxCollider::gerSize() const
	{
		return size;
	}

	ColliderType BoxCollider::getType()
	{
		return ColliderType::BOX;
	}

}