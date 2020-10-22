#ifndef HITTEST_H
#define HITTEST_H

#include "../include/BoxCollider.h"
#include "../include/CircleCollider.h"
#include "../include/LineCollider.h"
#include "../include/PointCollider.h"
#include "../include/PolygonCollider.h"

namespace gnCollider2D {

    namespace {
        // 交差した線の当たり判定
        bool isCrossingLine(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy)
        {
            auto t1{(cx - dx) * (ay - cy) + (cy - dy) * (cx - ax)};
            auto t2{(cx - dx) * (by - cy) + (cy - dy) * (cx - bx)};
            auto t3{(ax - bx) * (cy - ay) + (ay - by) * (ax - cx)};
            auto t4{(ax - bx) * (dy - ay) + (ay - by) * (ax - dx)};

            return t3 * t4 <= 0 && t1 * t2 <= 0;
        }
    }

    // 衝突判定の関数
    bool isHitTest(const BoxCollider     *_box,     const BoxCollider     &_collider){
        auto &bounds = _box->getBounds();
        auto &cb = _collider.getBounds();

        if (bounds.maxPos.x >= cb.minPos.x && bounds.minPos.x <= cb.maxPos.x 
            && bounds.maxPos.y >= cb.minPos.y && bounds.minPos.y <= cb.maxPos.y)
        {
            return true;
        }

        return false;
    }

    bool isHitTest(const BoxCollider     *_box,     const CircleCollider  &_collider){
        return false;
    }

    bool isHitTest(const BoxCollider     *_box,     const LineCollider    &_collider){
        const auto& bounds = _box->getBounds();
        const auto& col = _collider;

        float ax{bounds.minPos.x}, ay{bounds.minPos.y}, bx{bounds.minPos.x}, by{bounds.maxPos.y};
        float cx{col.getStart().x}, cy{col.getStart().y}, dx{col.getEnd().x}, dy{col.getEnd().y};

        return isCrossingLine(ax, ay, bx, by, cx, cy, dx, dy);
    }

    bool isHitTest(const BoxCollider     *_box,     const PointCollider   &_collider){
        return false;
    }

    bool isHitTest(const BoxCollider     *_box,     const PolygonCollider &_collider){
        return false;
    }

    bool isHitTest(const CircleCollider  *_circle,  const CircleCollider  &_collider){
        auto dist{_collider.getPos() - _circle->getPos()};
        auto c{dist.magnitude()};
        auto r{_collider.getRadius() + _circle->getRadius()};

        if(c <= r * r){
            return true;
        }

        return false;
    }

    bool isHitTest(const CircleCollider  *_circle,  const LineCollider    &_collider){
        return false;
    }

    bool isHitTest(const CircleCollider  *_circle,  const PointCollider   &_collider){
        return false;
    }

    bool isHitTest(const CircleCollider  *_circle,  const PolygonCollider &_collider){
        return false;
    }

    bool isHitTest(const LineCollider    *_line,    const LineCollider    &_collider){
        float ax{_line->getStart().x},    ay{_line->getStart().y},    bx{_line->getEnd().x},    by{_line->getStart().y};
        float cx{_collider.getStart().x}, cy{_collider.getStart().y}, dx{_collider.getEnd().x}, dy{_collider.getEnd().y};

        return isCrossingLine(ax, ay, bx, by, cx, cy, dx, dy);
    }

    bool isHitTest(const LineCollider    *_line,    const PointCollider   &_collider){
        return false;
    }

    bool isHitTest(const LineCollider    *_line,    const PolygonCollider &_collider){
        return false;
    }

    bool isHitTest(const PointCollider   *_point,   const PointCollider   &_collider){
        return false;
    }

    bool isHitTest(const PointCollider   *_point,   const PolygonCollider &_collider){
        return false;
    }

    bool isHitTest(const PolygonCollider *_polygon, const PolygonCollider &_collider){
        return false;
    }

}

#endif // HITTEST_H