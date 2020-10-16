#ifndef POLYGONCOLLIDER_H
#define POLYGONCOLLIDER_H

#include <vector>
#include <initializer_list>
#include "ICollider.h"
#include "Math/Vector2.h"

namespace gnCollider {

	class Vertex2D;
	class BoxCollider;
	class CircleCollider;
	class LineCollider;
	class PolygonCollider;

	struct Vertex2D{
		float x, y;
	};

	class PolygonCollider : public ICollider {

		using PolygonList = std::vector<Vertex2D>;

	public:
		PolygonCollider();
		PolygonCollider(std::initializer_list<Vertex2D> _polygon);
		~PolygonCollider() = default;

	private:
		PolygonList polygonList;
	};

}

#endif // !POLYGONCOLLIDER_H
