#ifndef CIRCLECOLLIDER_H
#define CIRCLECOLLIDER_H

#include "ICollider.h"
#include "Math/Vector2.h"

namespace gnCollider2D {

	class CircleCollider : public ICollider {
	public:
		CircleCollider();
		CircleCollider(const Vector2& _vector, float _radius);
		CircleCollider(float _x, float _y, float _r);
		~CircleCollider() = default;

		ColliderType getType() override;

		bool isHitTest(const BoxCollider&     _collider) override;
		bool isHitTest(const CircleCollider&  _collider) override;
		bool isHitTest(const LineCollider&    _collider) override;
		bool isHitTest(const PointCollider&   _collider) override;
		bool isHitTest(const PolygonCollider& _collider) override;

		void update(const Vector2& _vector, float _radius);

		Vector2& getPos();
		float getRadius();

	private:
		Vector2 position;
		float radius;
	};

}

#endif // !CIRCLECOLLIDER_H
