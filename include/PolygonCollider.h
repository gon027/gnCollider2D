#ifndef POLYGONCOLLIDER_H
#define POLYGONCOLLIDER_H

#include <vector>
#include <initializer_list>
#include "ICollider.h"
#include "Math/Vector2.h"

namespace gnCollider2D {
	
	using PolygonList = std::vector<Vector2>;

	class PolygonCollider : public ICollider {
	public:
		PolygonCollider() = default;
		PolygonCollider(std::initializer_list<Vector2> _polygon);
		~PolygonCollider() = default;

		ColliderType getType() override;

		bool isHitTest(const BoxCollider&     _collider) override;
		bool isHitTest(const CircleCollider&  _collider) override;
		bool isHitTest(const LineCollider&    _collider) override;
		bool isHitTest(const PointCollider&   _collider) override;
		bool isHitTest(const PolygonCollider& _collider) override;

		const PolygonList& getPolygonList() const;

	private:
		PolygonList polygonList;
	};

}

#endif // !POLYGONCOLLIDER_H
