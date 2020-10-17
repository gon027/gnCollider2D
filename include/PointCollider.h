#ifndef POINTCOLLIDER_H
#define POINTCOLLIDER_H

#include "ICollider.h"
#include "Math/Vector2.h"

namespace gnCollider {

	class PointCollider : public ICollider{
	public:
		PointCollider();
		PointCollider(const Vector2& _pos);
		~PointCollider();

		ColliderType getType() override;

		bool isHitTest(const BoxCollider&     _collider) override;
		bool isHitTest(const CircleCollider&  _collider) override;
		bool isHitTest(const LineCollider&    _collider) override;
		bool isHitTest(const PointCollider&   _collider) override;
		bool isHitTest(const PolygonCollider& _collider) override;

		void update(const Vector2 _pos);

		Vector2& getPos();

	private:
		Vector2 position;
	};

}

#endif // !POINTCOLLIDER_H
