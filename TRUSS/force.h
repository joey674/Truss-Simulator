#ifndef FORCE_H
#define FORCE_H

#include <QGraphicsItem>

class Joint;

class Force : public QGraphicsItem
{
public:
    Force(Joint* pjoint_ptr, double pxforce, double pyforce);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem *, QWidget*) override;
    Joint* get_joint_ptr();
    double get_xforce();
    double get_yforce();
    void set_xforce(double Fx);
    void set_yforce(double Fy);

private :
    Joint* joint_ptr;
    double xforce,yforce;
};

#endif // FORCE_H
