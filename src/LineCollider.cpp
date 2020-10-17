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

    bool LineCollider::isHitTest(const PointCollider& _collider) {
        return false;
    }

    bool LineCollider::isHitTest(const PolygonCollider& _collider) {
        return false;
    }

    Vector2 LineCollider::getStart() { 
        return start; 
    }

    Vector2 LineCollider::getEnd() {
        return end;
    }

    Vector2 LineCollider::getLength() {
        return end - start;
    }
}
