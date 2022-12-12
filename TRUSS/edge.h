#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>

class Joint;

class Edge : public QGraphicsItem
{
public:
    Edge(Joint* joint_ptr1, Joint* joint_ptr2);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    Joint* get_joint_ptr1();
    Joint* get_joint_ptr2();


private:
    Joint* joint_ptr1;
    Joint* joint_ptr2;
};

#endif // EDGE_H
