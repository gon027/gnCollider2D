#ifndef BOUNDS_H
#define BOUNDS_H

#include "Vector2.h"

namespace gnCollider2D {

	struct Bounds {
		Vector2 leftTop;
		Vector2 leftBottom;
		Vector2 rightTop;
		Vector2 rightBottom;

		Bounds()  = default;
		~Bounds() = default;
	};
}

#endif // !BOUNDS_H
