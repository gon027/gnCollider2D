#ifndef POLYGONCOLLIDER_H
#define POLYGONCOLLIDER_H

#include <vector>
#include <initializer_list>
#include "ICollider.h"
#include "Math/Vector2.h"

namespace gnCollider2D {

	struct Vertex2D{
		float x, y;
	};

	class PolygonCollider : public ICollider {

		using PolygonList = std::vector<Vertex2D>;

	public:
		PolygonCollider() = default;
		PolygonCollider(std::initializer_list<Vertex2D> _polygon);
		~PolygonCollider() = default;

		ColliderType getType() override;

		bool isHitTest(const BoxCollider&     _collider) override;
		bool isHitTest(const CircleCollider&  _collider) override;
		bool isHitTest(const LineCollider&    _collider) override;
		bool isHitTest(const PointCollider&   _collider) override;
		bool isHitTest(const PolygonCollider& _collider) override;

	private:
		PolygonList polygonList;
	};

}

#endif // !POLYGONCOLLIDER_H
