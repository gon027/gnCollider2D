#include "../include/LineCollider.h"
#include "../include/Intersect.h"

namespace gnCollider2D {

    bool hitLine(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy)
    {
        auto t1{(cx - dx) * (ay - cy) + (cy - dy) * (cx - ax)};
        auto t2{(cx - dx) * (by - cy) + (cy - dy) * (cx - bx)};
        auto t3{(ax - bx) * (cy - ay) + (ay - by) * (ax - cx)};
        auto t4{(ax - bx) * (dy - ay) + (ay - by) * (ax - dx)};

        return t3 * t4 <= 0 && t1 * t2 <= 0;
    }

    LineCollider::LineCollider()
        : start()
        , end()
    {

    }

    LineCollider::LineCollider(const Vector2& _sv, const Vector2& _gv)
        : start(_sv)
        , end(_gv)
    {
    }

    ColliderType LineCollider::getType() {
        return ColliderType::LINE;
    }

    bool LineCollider::isHitTest(const BoxCollider& _collider) {
        return Intersect::intersect(_collider, *this);
    }

    bool LineCollider::isHitTest(const CircleCollider& _collider) {
        return Intersect::intersect(_collider, *this);
    }

    bool LineCollider::isHitTest(const LineCollider& _collider) {
        return Intersect::intersect(*this, _collider);
    }

    bool LineCollider::isHitTest(const PointCollider& _collider) {
        return Intersect::intersect(*this, _collider);
    }

    bool LineCollider::isHitTest(const PolygonCollider& _collider) {
        return Intersect::intersect(*this, _collider);
    }

    void LineCollider::update(const Vector2 &_sv, const Vector2 &_gv)
    {
        start = _sv;
        end = _gv;
    }

    const Vector2& LineCollider::getStart() const { 
        return start; 
    }

    const Vector2& LineCollider::getEnd() const {
        return end;
    }

    const Vector2& LineCollider::getLength() const {
        return Vector2{ end - start };
    }
}
