#ifndef ICOLLIDER_H
#define ICOLLIDER_H

namespace gnCollider {

	enum class ColliderType : int {
		BOX,
		CIRCLE,
		LINE,
		POINT,
		POLYGON,
	};

	class ICollider {
	public:
		virtual ~ICollider() {};

		virtual ColliderType getType() = 0;
	};

}

#endif // !ICOLLIDER_H
