#ifndef HITTEST_H
#define HITTEST_H

#include "../include/BoxCollider.h"
#include "../include/CircleCollider.h"
#include "../include/LineCollider.h"
#include "../include/PointCollider.h"
#include "../include/PolygonCollider.h"

namespace gnCollider2D {

    // 衝突判定の関数
    bool isHitTest(const BoxCollider     &_collider, const BoxCollider     &_colliderr);
    bool isHitTest(const BoxCollider     &_collider, const CircleCollider  &_colliderr);
    bool isHitTest(const BoxCollider     &_collider, const LineCollider    &_colliderr);
    bool isHitTest(const BoxCollider     &_collider, const PointCollider   &_colliderr);
    bool isHitTest(const BoxCollider     &_collider, const PolygonCollider &_colliderr);
    bool isHitTest(const CircleCollider  &_collider, const CircleCollider  &_colliderr);
    bool isHitTest(const CircleCollider  &_collider, const LineCollider    &_colliderr);
    bool isHitTest(const CircleCollider  &_collider, const PointCollider   &_colliderr);
    bool isHitTest(const CircleCollider  &_collider, const PolygonCollider &_colliderr);
    bool isHitTest(const LineCollider    &_collider, const LineCollider    &_colliderr);
    bool isHitTest(const LineCollider    &_collider, const PointCollider   &_colliderr);
    bool isHitTest(const LineCollider    &_collider, const PolygonCollider &_colliderr);
    bool isHitTest(const PointCollider   &_collider, const PointCollider   &_colliderr);
    bool isHitTest(const PointCollider   &_collider, const PolygonCollider &_colliderr);
    bool isHitTest(const PolygonCollider &_collider, const PolygonCollider &_colliderr);

}

#endif // HITTEST_H