#ifndef POINTCOLLIDER_H
#define POINTCOLLIDER_H

#include "ICollider.h"
#include "Math/Vector2.h"

namespace gnCollider2D {

	class PointCollider : public ICollider{
	public:
		PointCollider();
		PointCollider(const Vector2& _pos);
		~PointCollider() = default;

		ColliderType getType() override;

		bool isHitTest(const BoxCollider&     _collider) override;
		bool isHitTest(const CircleCollider&  _collider) override;
		bool isHitTest(const LineCollider&    _collider) override;
		bool isHitTest(const PointCollider&   _collider) override;
		bool isHitTest(const PolygonCollider& _collider) override;

		void update(const Vector2 _pos);

		const Vector2& getPos() const ;

	private:
		Vector2 position;
	};

}

#endif // !POINTCOLLIDER_H
