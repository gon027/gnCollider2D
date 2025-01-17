#ifndef HITTEST_H
#define HITTEST_H

#include <cmath>
#include "../include/BoxCollider.h"
#include "../include/CircleCollider.h"
#include "../include/LineCollider.h"
#include "../include/PointCollider.h"
#include "../include/PolygonCollider.h"

namespace gnCollider2D {

    namespace {
        inline float dist(float _x, float _y)
        {
            return _x * _x + _y * _y;
        }

        // 交差した線の当たり判定
        inline bool isCrossingLine(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy)
        {
            auto t1{(cx - dx) * (ay - cy) + (cy - dy) * (cx - ax)};
            auto t2{(cx - dx) * (by - cy) + (cy - dy) * (cx - bx)};
            auto t3{(ax - bx) * (cy - ay) + (ay - by) * (ax - cx)};
            auto t4{(ax - bx) * (dy - ay) + (ay - by) * (ax - dx)};

            return t3 * t4 <= 0 && t1 * t2 <= 0;
        }

        inline bool isCheckBox(float _minX1, float _minY1, float _maxX1, float _maxY1, float _minX2, float _minY2, float _maxX2, float _maxY2)
        {
            if(_maxX1 >= _minX2 && _minX1 <= _maxX2 && _maxY1 >= _minY2 && _minY1 <= _maxY2){
                return true;
            }

            return false;
        }
    }

    namespace Intersect{

        //-----------------------------------------------
        // BoxCollider
        //-----------------------------------------------

        // Box vs Box
        inline bool intersect(const BoxCollider     &_box,     const BoxCollider     &_collider){
            auto &bounds = _box.getBounds();
            auto &cb = _collider.getBounds();

            if (bounds.maxPos.x >= cb.minPos.x
                && bounds.minPos.x <= cb.maxPos.x
                && bounds.maxPos.y >= cb.minPos.y
                && bounds.minPos.y <= cb.maxPos.y)
            {
                return true;
            }

            return false;
        }

        // Box vs Circle
        inline bool intersect(const BoxCollider     &_box,     const CircleCollider  &_collider){
            auto &c = _collider;
            auto &bounds = _box.getBounds();

            if (c.getPos().x > bounds.minPos.x && c.getPos().x < bounds.maxPos.x 
                && c.getPos().y > bounds.minPos.y - c.getRadius() && c.getPos().y < bounds.maxPos.y + c.getRadius())
            {
                return true;
            }

            if (c.getPos().x > bounds.minPos.x - c.getRadius() && c.getPos().x < bounds.maxPos.x + c.getRadius() 
                && c.getPos().y > bounds.minPos.y && c.getPos().y < bounds.maxPos.y)
            {
                return true;
            }

            float r = c.getRadius() * c.getRadius();

            float rx = bounds.minPos.x - c.getPos().x;
            float ry = bounds.minPos.y - c.getPos().y;
            float d = dist(rx, ry);
            if (d < r)
                return true;

            rx = bounds.maxPos.x - c.getPos().x;
            ry = bounds.minPos.y - c.getPos().y;
            d = dist(rx, ry);
            if (d < r)
                return true;

            rx = bounds.maxPos.x - c.getPos().x;
            ry = bounds.maxPos.y - c.getPos().y;
            d = dist(rx, ry);
            if (d < r)
                return true;

            rx = bounds.minPos.x - c.getPos().x;
            ry = bounds.maxPos.y - c.getPos().y;
            d = dist(rx, ry);
            if (d < r)
                return true;

            return false;
        }

        // Box vs Line
        inline bool intersect(const BoxCollider     &_box,     const LineCollider    &_collider){
            const auto& bounds = _box.getBounds();
            const auto& col = _collider;

            float ax{bounds.minPos.x},  ay{bounds.minPos.y},  bx{bounds.minPos.x}, by{bounds.maxPos.y};
            float cx{col.getStart().x}, cy{col.getStart().y}, dx{col.getEnd().x},  dy{col.getEnd().y};
            if(isCrossingLine(ax, ay, bx, by, cx, cy, dx, dy)) return true;

            ax = bounds.minPos.x; ay = bounds.minPos.y; bx = bounds.maxPos.x; by = bounds.minPos.y;
            if(isCrossingLine(ax, ay, bx, by, cx, cy, dx, dy)) return true;

            ax = bounds.maxPos.x; ay = bounds.minPos.y; bx = bounds.maxPos.x; by = bounds.maxPos.y;
            if(isCrossingLine(ax, ay, bx, by, cx, cy, dx, dy)) return true;

            ax = bounds.minPos.x; ay = bounds.maxPos.y; bx = bounds.maxPos.x; by = bounds.maxPos.y;
            if(isCrossingLine(ax, ay, bx, by, cx, cy, dx, dy)) return true;

            return false;
        }

        // Box vs Point
        inline bool intersect(const BoxCollider     &_box,     const PointCollider   &_collider){
            auto& bounds = _box.getBounds();
            auto& pos = _collider.getPos();

            if(pos.x >= bounds.minPos.x && pos.x <= bounds.maxPos.x 
                && pos.y >= bounds.minPos.y && pos.y <= bounds.maxPos.y){
                return true;
            }

            return false;
        }

        // Box vs Polygon
        inline bool intersect(const BoxCollider     &_box,     const PolygonCollider &_collider){
            return false;
        }

        //-----------------------------------------------
        // CiccleCollider
        //-----------------------------------------------

        // Circle vs Circle
        inline bool intersect(const CircleCollider  &_circle,  const CircleCollider  &_collider){
            auto dist{_collider.getPos() - _circle.getPos()};
            auto c{dist.magnitude()};
            auto r{_collider.getRadius() + _circle.getRadius()};

            if(c <= r * r){
                return true;
            }

            return false;
        }

        // Circle vs Line
        inline bool intersect(const CircleCollider  &_circle,  const LineCollider    &_collider){
            // 始点から円の中心へのベクトル
            auto a = Vector2{_circle.getPos().x - _collider.getStart().x, _circle.getPos().y - _collider.getStart().y};

            // 終点から円の中心へのベクトル
            auto b = Vector2{_circle.getPos().x - _collider.getEnd().x, _circle.getPos().y - _collider.getEnd().y};

            // 線分の長さ
            auto length = _collider.getEnd() - _collider.getStart();
            auto nomal = length.normalized();

            // 中心から線分への最短距離
            float projection = a.x * nomal.y - nomal.x * a.y;

            if (std::fabs(projection) < _circle.getRadius())
            {
                float dot1 = a.x * length.x + a.y * length.y;
                float dot2 = b.x * length.x + b.y * length.y;

                if (dot1 * dot2 <= 0.0f)
                {
                    return true;
                }

                if (a.magnitude() < _circle.getRadius() || b.magnitude() < _circle.getRadius())
                {
                    return true;
                }
            }

            return false;
        }

        // Circle vs Point
        inline bool intersect(const CircleCollider  &_circle,  const PointCollider   &_collider){
            auto d = _collider.getPos() - _circle.getPos();

            if(d.magnitude() <= _circle.getRadius() * _circle.getRadius()){
                return true;
            }

            return false;
        }

        // Circle vs Polygon
        inline bool intersect(const CircleCollider  &_circle,  const PolygonCollider &_collider){
            return false;
        }

        //-----------------------------------------------
        // LineCollider
        //-----------------------------------------------

        // Line vs Line
        inline bool intersect(const LineCollider    &_line,    const LineCollider    &_collider){
            float ax{_line.getStart().x},    ay{_line.getStart().y},    bx{_line.getEnd().x},    by{_line.getStart().y};
            float cx{_collider.getStart().x}, cy{_collider.getStart().y}, dx{_collider.getEnd().x}, dy{_collider.getEnd().y};

            return isCrossingLine(ax, ay, bx, by, cx, cy, dx, dy);
        }

        // Line vs Point
        inline bool intersect(const LineCollider    &_line,    const PointCollider   &_collider){
            Vector2 v1{_line.getEnd().x - _line.getStart().x, _line.getEnd().y - _line.getStart().y};
            Vector2 v2{_collider.getPos().x - _line.getStart().x, _collider.getPos().y - _line.getStart().y};

            float l1 = std::sqrt(dist(v1.x, v1.y));
            float l2 = std::sqrt(dist(v2.x, v2.y));

            if ((v1.x * v2.x) + (v1.y * v2.y) == (l1 * l2) && l1 >= l2)
            {
                return true;
            }

            return false;
        }

        // Line vs Polygon
        inline bool intersect(const LineCollider    &_line,    const PolygonCollider &_collider){
            return false;
        }

        //-----------------------------------------------
        // PointCollider
        //-----------------------------------------------

        // Point vs Point
        inline bool intersect(const PointCollider   &_point,   const PointCollider   &_collider){
            if(_point.getPos().x == _collider.getPos().x && _point.getPos().y == _collider.getPos().y){
                return true;
            }
            
            return false;
        }

        // Point vs Polygon 
        inline bool intersect(const PointCollider   &_point,   const PolygonCollider &_collider){
            return false;
        }

        //-----------------------------------------------
        // PolygonCollider
        //-----------------------------------------------

        // Polygon vs Polygon
        inline bool intersect(const PolygonCollider &_polygon, const PolygonCollider &_collider){
            return false;
        }

    } // Intersect

} // gnCollider

#endif // HITTEST_H