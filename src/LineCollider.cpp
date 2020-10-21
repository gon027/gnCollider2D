#include "../include/LineCollider.h"
#include "../include/BoxCollider.h"
#include "../include/CircleCollider.h"
#include "../include/PointCollider.h"
#include "../include/PolygonCollider.h"

#include <cmath>

namespace gnCollider2D {

    float cross(float _x1, float _y1, float _x2, float _y2)
    {
        return _x1 * _y2 - _x2 * _y1;
    }

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
        const auto& bounds = _collider.getBounds();

        float ax{ bounds.minPos.x }, ay{ bounds.minPos.y }, bx{ bounds.minPos.x }, by{ bounds.maxPos.y };
        float cx{ start.x }, cy{ start.y }, dx{ end.x }, dy{ end.y };
        return hitLine(ax, ay, bx, by, cx, cy, dx, dy);

        ax = bounds.minPos.x; ay = bounds.minPos.y; bx = bounds.maxPos.x; by = bounds.minPos.y;
        return hitLine(ax, ay, bx, by, cx, cy, dx, dy);

        ax = bounds.maxPos.x; ay = bounds.minPos.y; bx = bounds.maxPos.x;by = bounds.maxPos.y;
        return hitLine(ax, ay, bx, by, cx, cy, dx, dy);

        ax = bounds.minPos.x; ay = bounds.maxPos.y; bx = bounds.maxPos.x; by = bounds.maxPos.y;
        return hitLine(ax, ay, bx, by, cx, cy, dx, dy);

        return false;
    }

    bool LineCollider::isHitTest(const CircleCollider& _collider) {
        // 始点から円の中心へのベクトル
        auto a = Vector2{ _collider.getPos().x - start.x, _collider.getPos().y - end.y };
        
        // 終点から円の中心へのベクトル
        auto b = Vector2{ _collider.getPos().x - end.x, _collider.getPos().y - end.y };
        
        // 線分の長さ
        auto length = getLength();
        auto nomal = length.normalized();

        // 中心から線分への最短距離
        float projection = a.x * nomal.y - nomal.x * b.y;

        if(fabs(projection) < _collider.getRadius()){
            float dot1 = a.x * length.x + a.y * length.y;
            float dot2 = b.x * length.x * b.y * length.y;

            if(dot1 * dot2 <= 0.0f){
                return true;
            }

            if(a.magnitude() < _collider.getRadius() || b.magnitude() < _collider.getRadius()){
                return true;
            }
        }

        return false;
    }

    bool LineCollider::isHitTest(const LineCollider& _collider) {
        auto& col = _collider;

        float ax{ start.x     }, ay{ start.y     }, bx{ end.x     }, by{ end.y     };
        float cx{ col.start.x }, cy{ col.start.y }, dx{ col.end.x }, dy{ col.end.y };

        return hitLine(ax, ay, bx, by, cx, cy, dx, dy);
    }

    bool LineCollider::isHitTest(const PointCollider& _collider) {
        return false;
    }

    bool LineCollider::isHitTest(const PolygonCollider& _collider) {
        return false;
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
