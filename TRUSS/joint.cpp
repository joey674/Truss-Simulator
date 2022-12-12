#include "joint.h"
#include "edge.h"
#include <iostream>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <mainwindow.h>
#include <QGraphicsScene>


Joint::Joint(int pnum, double px, double py, bool psupport)
{
    num = pnum;
    if_support = psupport;
    p_x = px;
    p_y = py;
    setPos(p_x-400,p_y-400);
    setFlags(QGraphicsItem::ItemIsSelectable);
    setZValue(3);
}

QRectF Joint::boundingRect() const
{
    return QRectF(-7, -7, 14, 14);
}

QPainterPath Joint::shape() const
{
    QPainterPath hitbox;
    hitbox.addEllipse(-7, -7, 14, 14);

    return hitbox;
}

void Joint::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*){

    painter->setBrush(Qt::red);

    QPen pen;
    pen.setStyle(Qt::SolidLine);

    if(if_support == 1){
        painter->setBrush(Qt::black);
      }

    if(this->isSelected() == true){
        painter->setPen(pen);
        painter->setBrush(Qt::white);
    }
    painter->drawEllipse(-7, -7, 14, 14);


}

int Joint::type() const
{
    return m_type;
}


int Joint::get_num(){

    return num;
}

void Joint::set_num(int pnum) {

    num = pnum;
}

bool Joint::get_support(){

    return if_support;
}

void Joint::set_support(bool psupport){

    if_support = psupport;
}

double Joint::get_p_x() {

    return p_x;
}

double Joint::get_p_y() {

    return p_y;
}

void Joint::set_newp_x(double newx)
{
    newp_x = newx;
}

void Joint::set_newp_y(double newy)
{
    newp_y = newy;
}

double Joint::get_newp_x()
{
    return newp_x;
}

double Joint::get_newp_y()
{
    return newp_y;
}

void Joint::set_position(double px,double py){

    newp_x=px;
    newp_y=py;

}

//void Joint::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    double px = p_x;
//    double py = p_y;
 //   if(this->isSelected()){

//    }
 //   QGraphicsItem::mousePressEvent(event);
//}


void Joint::set_edges(Edge* new_edge){

   attached_edges.push_back(new_edge);
}

vector<Edge*>& Joint::get_edges(){

    return attached_edges;
}

void Joint::remove_edge(Edge *edge){

  for(int i =0; i < attached_edges.size(); i++  ){
        if(edge == attached_edges[i]){
            attached_edges.erase(attached_edges.begin()+i);
            break;
         }
    }
}
