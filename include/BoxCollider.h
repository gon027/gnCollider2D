#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "ICollider.h"
#include "Math/Vector2.h"
#include "Math/Bounds.h"

namespace gnCollider {

	class CircleCollider;
	class LineCollider;
	class PointCollider;
	class PolygonCollider;

	class BoxCollider : public ICollider {
	public:
		BoxCollider(Vector2& _pos, Vector2& _min, Vector2& _max);
		BoxCollider() = default;
		~BoxCollider() = default;

		bool isHitTest(BoxCollider& _collider);
		bool isHitTest(const CircleCollider& _collider);
		bool isHitTest(const PolygonCollider& _collider);

		void update(const Vector2& _pos, const Bounds& _bounds);

		Vector2 getPos() const;
		Vector2 getMin() const;
		Vector2 getMax() const;
		Vector2 gerSize() const;

		virtual ColliderType getType() override;

	private:
		Vector2 center;
		Vector2 size;
		Bounds bounds;
	};
}

#endif // !BOXCOLLIDER_H
