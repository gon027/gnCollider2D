#include "../include/BoxCollider.h"
#include "../include/Intersect.h"

namespace gnCollider2D {

	ColliderType BoxCollider::getType()
	{
		return ColliderType::BOX;
	}

	bool BoxCollider::isHitTest(const BoxCollider& _collider)
	{
		return Intersect::intersect(*this, _collider);
	}

	bool BoxCollider::isHitTest(const CircleCollider& _collider)
	{
		return Intersect::intersect(*this, _collider);
	}

	bool BoxCollider::isHitTest(const PointCollider& _collider){
		return Intersect::intersect(*this, _collider);
	}

	bool BoxCollider::isHitTest(const LineCollider& _collider){
		return Intersect::intersect(*this, _collider);
	}

	bool gnCollider2D::BoxCollider::isHitTest(const PolygonCollider& _collider)
	{
		return Intersect::intersect(*this, _collider);
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