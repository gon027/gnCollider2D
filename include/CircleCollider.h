#ifndef CIRCLECOLLIDER_H
#define CIRCLECOLLIDER_H

#include "ICollider.h"
#include "Math/Vector2.h"

namespace gnCollider {

	class BoxCollider;
	class LineCollider;
	class PointCollider;
	class PolygonCollider;

	class CircleCollider : public ICollider {
	public:
		CircleCollider();
		CircleCollider(const Vector2& _vector, const Vector2& _radius);
		CircleCollider(float _x, float _y, float _rx, float _ry);
		~CircleCollider() = default;

		void update(const Vector2& _vector, const Vector2& _radius);

		bool isHitTest(const CircleCollider& _circleCollider);
		bool isHitTest(const BoxCollider& _collider);
		bool isHitTest(const PolygonCollider& _collider);

		ColliderType getType() override;

		Vector2& getPos();
		Vector2& getRadius();

	private:
		Vector2 position;
		Vector2 radius;
	};

}

#endif // !CIRCLECOLLIDER_H
