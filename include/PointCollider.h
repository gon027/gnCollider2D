#ifndef POINTCOLLIDER_H
#define POINTCOLLIDER_H

#include "Vector2.h"
#include "Math/ICollider.h"

namespace gnCollider {

	class BoxCollider;
	class CircleCollider;
	class LineCollider;
	class PolygonCollider;

	class PointCollider : public ICollider{
	public:
		PointCollider();
		PointCollider(const Vector2& _pos);
		~PointCollider();

		void update(const Vector2 _pos);

		bool isHitTest(const PointCollider& _collider);
		bool isHitTest(const BoxCollider& _collider);
		bool isHitTest(const CircleCollider& _collider);
		bool isHitTest(const PolygonCollider& _collider);
		
		ColliderType getType() override;

		Vector2& getPos();

	private:
		Vector2 position;
	};

}

#endif // !POINTCOLLIDER_H
