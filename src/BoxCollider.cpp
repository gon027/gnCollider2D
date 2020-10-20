#include "../include/BoxCollider.h"
#include "../include/CircleCollider.h"
#include "../include/LineCollider.h"
#include "../include/PointCollider.h"
#include "../include/PolygonCollider.h"
#include "../include/Math/Math.h"

namespace gnCollider2D {

	ColliderType BoxCollider::getType()
	{
		return ColliderType::BOX;
	}

	bool BoxCollider::isHitTest(const BoxCollider& _collider)
	{
		auto &cb = _collider.getBounds();

		if (bounds.maxPos.x >= cb.minPos.x 
			&& bounds.minPos.x <= cb.maxPos.x 
			&& bounds.maxPos.y >= cb.minPos.y 
			&& bounds.minPos.y <= cb.maxPos.y)
		{
			return true;
		}

		return false;
	}

	bool BoxCollider::isHitTest(const CircleCollider& _collider)
	{
		auto c = _collider;
		auto &b = bounds;

		if (c.getPos().x > b.minPos.x && c.getPos().x < b.maxPos.x && c.getPos().y > b.minPos.y - c.getRadius() && c.getPos().y < b.maxPos.y + c.getRadius())
		{
			return true;
		}

		if (c.getPos().x > b.minPos.x - c.getRadius() && c.getPos().x < b.maxPos.x + c.getRadius() && c.getPos().y > b.minPos.y && c.getPos().y < b.maxPos.y)
		{
			return true;
		}

		float r = c.getRadius() * c.getRadius();

		float rx = bounds.minPos.x - c.getPos().x;
		float ry = bounds.minPos.y - c.getPos().y;
		float d = dist(rx, ry);
		if (d < r)
			return true;

		rx = bounds.maxPos.x - c.getPos().x;
		ry = bounds.minPos.y - c.getPos().y;
		d = dist(rx, ry);
		if (d < r)
			return true;

		rx = bounds.maxPos.x - c.getPos().x;
		ry = bounds.maxPos.y - c.getPos().y;
		d = dist(rx, ry);
		if (d < r)
			return true;

		rx = bounds.minPos.x - c.getPos().x;
		ry = bounds.maxPos.y - c.getPos().y;
		d = dist(rx, ry);
		if (d < r)
			return true;

		return false;
	}

	bool BoxCollider::isHitTest(const PointCollider& _collider){
		return false;
	}

	bool BoxCollider::isHitTest(const LineCollider& _collider){
		return false;
	}

	bool gnCollider2D::BoxCollider::isHitTest(const PolygonCollider& _collider)
	{
		return false;
	}

	void BoxCollider::update(const Vector2 &_v, float _width, float _height)
	{
		auto w = _width / 2.0f;
		auto h = _height / 2.0f;

		bounds.center = _v;
		bounds.minPos.setPos(_v.x - w, _v.y - h);
		bounds.maxPos.setPos(_v.x + w, _v.y + h);
		bounds.size.setPos(_width, _height);
	}

	const Bounds &BoxCollider::getBounds() const
	{
		return bounds;
	}
}