#ifndef ICOLLIDER_H
#define ICOLLIDER_H

#include <vector>

namespace gnCollider2D {

	class Vector2;

	class BoxCollider;
	class CircleCollider;
	class LineCollider;
	class PointCollider;
	class PolygonCollider;

	enum class ColliderType : int {
		BOX,
		CIRCLE,
		LINE,
		POINT,
		POLYGON,
	};

	class ICollider {
	public:
		virtual ~ICollider() {};

		virtual ColliderType getType() = 0;

		virtual bool isHitTest(const BoxCollider&     _collider) = 0;
		virtual bool isHitTest(const CircleCollider&  _collider) = 0;
		virtual bool isHitTest(const LineCollider&    _collider) = 0;
		virtual bool isHitTest(const PointCollider&   _collider) = 0;
		virtual bool isHitTest(const PolygonCollider& _collider) = 0;
	};

}

#endif // !ICOLLIDER_H
