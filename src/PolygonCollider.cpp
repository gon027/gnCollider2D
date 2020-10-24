#include "../include/PolygonCollider.h"
#include "../include/Intersect.h"

namespace gnCollider2D{

    PolygonCollider::PolygonCollider(std::initializer_list<Vector2> _polygon)
    {    
    }

    ColliderType PolygonCollider::getType(){
        return ColliderType::POLYGON;
    }

    bool PolygonCollider::isHitTest(const BoxCollider& _collider){
        return Intersect::intersect(_collider, *this);
    }

    bool PolygonCollider::isHitTest(const CircleCollider& _collider){
        return Intersect::intersect(_collider, *this);
    }

    bool PolygonCollider::isHitTest(const LineCollider& _collider){
        return Intersect::intersect(_collider, *this);
    }

    bool PolygonCollider::isHitTest(const PointCollider& _collider){
        return Intersect::intersect(_collider, *this);
    }

    bool PolygonCollider::isHitTest(const PolygonCollider& _collider){
        return Intersect::intersect(*this, _collider);
    }

    const PolygonList& PolygonCollider::getPolygonList() const{
        return polygonList;
    }
}