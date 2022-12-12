#include "edge.h"
#include "joint.h"
#include <math.h>
#include <QPainter>

Edge::Edge(Joint* pjoint_ptr1, Joint* pjoint_ptr2)
{
    joint_ptr1 = pjoint_ptr1;
    joint_ptr2 = pjoint_ptr2;
    (joint_ptr1)->set_edges(this);
    (joint_ptr2)->set_edges(this);
    setZValue(1);
    setFlags(QGraphicsItem::ItemIsSelectable);
}

QRectF Edge::boundingRect() const{

    double min_x = std::min(joint_ptr1->x(),joint_ptr2->x());
    double min_y = std::min(joint_ptr1->y(),joint_ptr2->y());
    double dist_x = fabs(joint_ptr1->x() - joint_ptr2->x());
    double dist_y = fabs(joint_ptr1->y() - joint_ptr2->y());
    return QRectF(min_x-10,min_y-10,dist_x+20,dist_y+20);
}

QPainterPath Edge::shape() const{
    QPainterPath hitbox;
    double x1=joint_ptr1->x();
    double x2=joint_ptr2->x();
    double y1=joint_ptr1->y();
    double y2=joint_ptr2->y();
    double angle = atan2(y2-y1,x2-x1);
    hitbox.moveTo(x1+8*sin(angle),y1-8*cos(angle));
    hitbox.lineTo(x2+8*sin(angle),y2-8*cos(angle));
    hitbox.lineTo(x2-8*sin(angle),y2+8*cos(angle));
    hitbox.lineTo(x1-8*sin(angle),y1+8*cos(angle));
    hitbox.closeSubpath();


    return hitbox;
}

void Edge::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*){

    painter->setPen(Qt::SolidLine);
    QPen pen;
    pen.setStyle(Qt::DashLine);

    if(this->isSelected() == true){
        painter->setPen(pen);
    }

    painter->drawLine(joint_ptr1->x(),joint_ptr1->y(),joint_ptr2->x(),joint_ptr2->y());
}

Joint* Edge::get_joint_ptr1(){

    return joint_ptr1;
}

Joint* Edge::get_joint_ptr2(){

    return joint_ptr2;
}
