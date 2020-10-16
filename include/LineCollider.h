#ifndef LINECOLLIDER_H
#define LINECOLLIDER_H

#include "ICollider.h"
#include "Math/Vector2.h"

namespace gnCollider {

    class BoxCollider;
    class CircleCollider;
    class PointCollider;
    class PolygonCollider;

    class LineCollider : public ICollider {
    public:
        LineCollider() = default;
        LineCollider(const Vector2& _sv, const Vector2& _gv);
        ~LineCollider() = default;

        ColliderType getType() override;

        void update(const Vector2& _sv, const Vector2& _gv);

        bool isHitTest(const BoxCollider& _collider);
        bool isHitTest(const CircleCollider& _collider);
        bool isHitTest(const PointCollider& _collider);
        bool isHitTest(const PolygonCollider& _collider);

        Vector2 getStart();
        Vector2 getEnd();
        Vector2 getLength();

    private:
        Vector2 start;
        Vector2 end;
    };

}
#endif // !LINECOLLIDER_H
