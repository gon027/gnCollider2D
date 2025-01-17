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

        const Vector2& getStart()  const;
        const Vector2& getEnd()    const;
        const Vector2& getLength() const;

    private:
        Vector2 start;
        Vector2 end;
    };

}

#endif // !LINECOLLIDER_H
