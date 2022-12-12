#include "force.h"
#include "joint.h"
#include <math.h>
#include <QPainter>

Force::Force(Joint* pjoint_ptr, double pxforce, double pyforce)
{
    xforce = pxforce;
    yforce = pyforce;
    joint_ptr = pjoint_ptr;
    setZValue(2);
    setFlags(QGraphicsItem::ItemIsSelectable);
}

QRectF Force::boundingRect() const
{
    double New_x,New_y,min_x,min_y,Angle;
    Angle = atan2(yforce,xforce);
    New_x = joint_ptr->x() + 50 * cos(Angle);
    New_y = joint_ptr->y() + 50 * sin(Angle);
    min_x = std::min(joint_ptr->x(),New_x);
    min_y = std::min(joint_ptr->y(),New_y);
    return QRectF(min_x-15,min_y-15,50 * fabs(cos(Angle))+30,50 * fabs(sin(Angle))+30);
}

QPainterPath Force::shape() const
{
    QPainterPath hitbox;
    double angle = atan2(yforce,xforce);
    double new_x = joint_ptr->x() + 50 * cos(angle);
    double new_y = joint_ptr->y() + 50 * sin(angle);
    hitbox.moveTo(joint_ptr->x()+10*sin(angle),joint_ptr->y()-10*cos(angle));
    hitbox.lineTo(new_x+10*sin(angle),new_y-10*cos(angle));
    hitbox.lineTo(new_x-10*sin(angle),new_y+10*cos(angle));
    hitbox.lineTo(joint_ptr->x()-10*sin(angle),joint_ptr->y()+10*cos(angle));
    hitbox.closeSubpath();


    return hitbox;
}

void Force::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    double new_x,new_y,angle;
    angle = atan2(yforce,xforce);
    new_x = joint_ptr->x() + 50 * cos(angle);
    new_y = joint_ptr->y() + 50 * sin(angle);
    QPen pen;
    pen.setColor(Qt::green);
    pen.setWidth(2);
    painter->setPen(pen);

    if(this->isSelected() == true){
        pen.setColor(Qt::blue);
        painter->setPen(pen);
    }
    painter->drawLine(joint_ptr->x(),joint_ptr->y(), new_x, new_y);
    painter->drawLine(new_x, new_y,new_x-15*sin(0.67*M_PI+angle),new_y+15*cos(0.67*M_PI+angle));
    painter->drawLine(new_x, new_y,new_x+15*sin(-0.33*M_PI-angle),new_y+15*cos(-0.33*M_PI-angle));
}

Joint* Force::get_joint_ptr(){

    return joint_ptr;
}

double Force::get_xforce(){

    return xforce;
}

double Force::get_yforce(){

    return yforce;
}

void Force::set_xforce(double Fx) {
    xforce=Fx;
}

void Force::set_yforce(double Fy) {
    yforce=Fy;
}
