#ifndef LINECOLLIDER_H
#define LINECOLLIDER_H

#include "ICollider.h"
#include "Math/Vector2.h"

namespace gnCollider2D {

    class LineCollider : public ICollider {
    public:
        LineCollider();
        LineCollider(const Vector2& _sv, const Vector2& _gv);
        ~LineCollider() = default;

        ColliderType getType() override;

        bool isHitTest(const BoxCollider&     _collider) override;
        bool isHitTest(const CircleCollider&  _collider) override;
        bool isHitTest(const LineCollider&    _collider) override;
        bool isHitTest(const PointCollider&   _collider) override;
        bool isHitTest(const PolygonCollider& _collider) override;

        void update(const Vector2& _sv, const Vector2& _gv);

        Vector2 getStart();
        Vector2 getEnd();
        Vector2 getLength();

    private:
        Vector2 start;
        Vector2 end;
    };

}

#endif // !LINECOLLIDER_H
