#ifndef JOINT_H
#define JOINT_H

#include <vector>
#include <QGraphicsItem>


using namespace std;

class Edge;

class Joint : public QGraphicsItem
{
public:
       Joint(int pnum, double px, double py, bool psupport);

       QRectF boundingRect() const override;
       QPainterPath shape() const override;
       void paint(QPainter * painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

       virtual int type() const override;
       //get' and  set's
       bool get_support();
       void set_support(bool psupport);
       int get_num();
       void set_num(int pnum);
       double get_p_x();
       double get_p_y();
       void set_newp_x(double newx);
       void set_newp_y(double newy);
       double get_newp_x();
       double get_newp_y();
       void set_edges(Edge* new_edge);
       vector<Edge*>& get_edges();
       void remove_edge(Edge* edge);
       void set_position(double px,double py);

       //void mousePressEvent(QGraphicsSceneMouseEvent *event) override;


   private:
       int num;
       int m_type = 700;
       vector<Edge* > attached_edges;
       bool if_support;
       double p_x, p_y;
       double newp_x,newp_y;


};

#endif // JOINT_H
