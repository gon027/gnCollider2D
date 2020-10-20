#include "../include/LineCollider.h"
#include "../include/BoxCollider.h"
#include "../include/CircleCollider.h"
#include "../include/PointCollider.h"
#include "../include/PolygonCollider.h"

namespace gnCollider2D {

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

    void LineCollider::update(const Vector2& _sv, const Vector2& _gv) {
        start = _sv;
        end = _gv;
    }

    bool LineCollider::isHitTest(const BoxCollider& _collider) {
        return false;
    }

    bool LineCollider::isHitTest(const CircleCollider& _collider) {
        return false;
    }

    bool LineCollider::isHitTest(const LineCollider& _collider) {
        // A: col.start, B: col.end, C: start, D: end

        auto& col = _collider;

        auto t1 = (start.x - end.x) * (col.start.y - start.y) + (start.y - end.y) * (start.x - col.start.x);
        auto t2 = (start.x - end.x) * (col.end.y - start.y) + (start.y - end.y) * (start.x - col.end.x);
        auto t3 = (col.start.x - col.end.x) * (end.x - col.start.x) + (col.start.y - col.end.y) * (start.x - col.end.x);
        auto t4 = (col.start.x - col.end.x) * (end.y - col.start.x) + (col.start.y - col.end.y) * (start.x - end.x);

        return t3 * t4 < 0 && t1 * t2 < 0;
    }

    bool LineCollider::isHitTest(const PointCollider& _collider) {
        return false;
    }

    bool LineCollider::isHitTest(const PolygonCollider& _collider) {
        return false;
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
