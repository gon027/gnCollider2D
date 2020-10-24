#include "../include/PolygonCollider.h"
#include "../include/Intersect.h"

namespace gnCollider2D{

    PolygonCollider::PolygonCollider(std::initializer_list<Vertex2D> _polygon)
    {    
    }

    ColliderType PolygonCollider::getType(){
        return ColliderType::POLYGON;
    }

    bool PolygonCollider::isHitTest(const BoxCollider& _collider){
        return false;
    }

     bool PolygonCollider::isHitTest(const CircleCollider& _collider){
        return false;
    }

     bool PolygonCollider::isHitTest(const LineCollider& _collider){
        return false;
    }

     bool PolygonCollider::isHitTest(const PointCollider& _collider){
        return false;
    }

     bool PolygonCollider::isHitTest(const PolygonCollider& _collider){
        return false;
    }
}