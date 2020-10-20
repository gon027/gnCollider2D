#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "ICollider.h"
#include "Math/Vector2.h"
#include "Math/Bounds.h"

namespace gnCollider2D {

	class BoxCollider : public ICollider {
	public:
		BoxCollider() = default;
		~BoxCollider() = default;

		virtual ColliderType getType() override;

		bool isHitTest(const BoxCollider&     _collider) override;
		bool isHitTest(const CircleCollider&  _collider) override;
		bool isHitTest(const LineCollider&    _collider) override;
		bool isHitTest(const PointCollider&   _collider) override;
		bool isHitTest(const PolygonCollider& _collider) override;

		void update(const Vector2 &_v, float _width, float _height);

		const Bounds& getBounds() const;

	private:
		Bounds bounds;
	};
	
}

#endif // !BOXCOLLIDER_H
