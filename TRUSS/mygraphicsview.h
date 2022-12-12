#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "truss.h"
#include "joint.h"
#include "edge.h"
#include "force.h"
#include "myscene.h"


class myGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit myGraphicsView(QWidget *parent = nullptr);
    myScene *scene;
    Truss *currentTruss;
    Truss *deformedTruss;
    QList<QGraphicsItem *> itemList;
    int selectedEdge;
    int selectedForce;
    int selectedJoint1,selectedJoint2;


protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

signals:
    void mouseMoveSignal(QPoint point);
    void JointSignal(int i);
    void EdgeSignal(int i);
    void ForceSignal(int i);
    void noItemSignal();
    void selectedEdgeSignal(int i);
    void selectedForceSignal(int i);
    void selectedJointSignal(int i,int j);

private slots:
    void on_action4();
    void on_action5();
    void on_action8();
};

#endif // MYGRAPHICSVIEW_H
