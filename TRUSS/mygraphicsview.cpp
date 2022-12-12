#include "mygraphicsview.h"
#include <QMouseEvent>
#include<QGraphicsSceneMouseEvent>
#include <QList>
#include <QDebug>
#include <QTransform>


myGraphicsView::myGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    scene = new myScene(this);
    scene->setSceneRect(-350,-350,700,700);
    currentTruss = nullptr;
    deformedTruss = nullptr;
    this->setScene(scene);

    connect(scene->menu->actions()[4],SIGNAL(triggered()),this,SLOT(on_action4()));
    connect(scene->menu->actions()[5],SIGNAL(triggered()),this,SLOT(on_action5()));
    connect(scene->menu->actions()[8],SIGNAL(triggered()),this,SLOT(on_action8()));
}

void myGraphicsView::mousePressEvent(QMouseEvent *event)
{
    QTransform transform;
    QPoint p = event->pos();
    QPointF p_scene = mapToScene(p);
    QGraphicsItem *item_s = scene->itemAt(p_scene,transform);
    if(event->button() == Qt::LeftButton) {
        if(item_s!=nullptr){
            if(item_s->zValue() == 3) {
                for(int i = 0;i<currentTruss->v_joint_ptr.size();i++){
                    if(item_s->pos() == currentTruss->v_joint_ptr[i]->pos()){
                        emit JointSignal(i);
                    }
                }
            }
            else if(item_s->zValue() == 1){
                for(int i = 0;i<currentTruss->v_edge_ptr.size();i++){
                    if(item_s->boundingRect().center() == currentTruss->v_edge_ptr[i]->boundingRect().center()){
                        emit EdgeSignal(i);
                    }
                }
            }
            else if(item_s->zValue() == 2){
                for(int i = 0;i<currentTruss->v_force_ptr.size();i++){
                    if(item_s->boundingRect().center() == currentTruss->v_force_ptr[i]->boundingRect().center()){
                        emit ForceSignal(i);
                    }
                }
            }
        }
        else{
            emit noItemSignal();
        }
    }

    if(event->button() == Qt::RightButton){
        scene->set_Point(event->pos());
        QList<QAction*> Actions=scene->menu->actions();
        if(currentTruss!=nullptr && deformedTruss == nullptr ){
            itemList = scene->selectedItems();
            if(itemList.size()<2){
                if(item_s == nullptr){
                    Actions[0]->setEnabled(true);
                    Actions[1]->setEnabled(true);
                    Actions[2]->setEnabled(false);
                    Actions[4]->setEnabled(false);
                    Actions[5]->setEnabled(false);
                    Actions[7]->setEnabled(false);
                    Actions[8]->setEnabled(false);
                }
                else if(item_s->zValue() == 3){
                    QPointF point(item_s->pos().x()+400,item_s->pos().y()+400);
                    scene->set_Point(point);
                    Actions[0]->setEnabled(false);
                    Actions[1]->setEnabled(false);
                    Actions[2]->setEnabled(true);
                    Actions[4]->setEnabled(false);
                    Actions[5]->setEnabled(false);
                    Actions[7]->setEnabled(true);
                    Actions[8]->setEnabled(false);
                }
                else if(item_s->zValue() == 1){
                    for(int i = 0;i<currentTruss->v_edge_ptr.size();i++){
                        if(item_s->boundingRect().center() == currentTruss->v_edge_ptr[i]->boundingRect().center()){
                            selectedEdge = i;
                        }
                    }
                    Actions[0]->setEnabled(false);
                    Actions[1]->setEnabled(false);
                    Actions[2]->setEnabled(false);
                    Actions[4]->setEnabled(false);
                    Actions[5]->setEnabled(true);
                    Actions[7]->setEnabled(false);
                    Actions[8]->setEnabled(false);
                }
                else if(item_s->zValue() == 2){
                    for(int i = 0;i<currentTruss->v_force_ptr.size();i++){
                        if(item_s->boundingRect().center() == currentTruss->v_force_ptr[i]->boundingRect().center()){
                            selectedForce = i;
                        }
                    }
                    Actions[0]->setEnabled(false);
                    Actions[1]->setEnabled(false);
                    Actions[2]->setEnabled(false);
                    Actions[4]->setEnabled(false);
                    Actions[5]->setEnabled(false);
                    Actions[7]->setEnabled(false);
                    Actions[8]->setEnabled(true);
                }
            }
            else if(itemList.size() == 2){
                if(itemList.at(0)->zValue() == 3 && itemList.at(1)->zValue() == 3){
                    Actions[0]->setEnabled(false);
                    Actions[1]->setEnabled(false);
                    Actions[2]->setEnabled(false);
                    Actions[4]->setEnabled(true);
                    Actions[5]->setEnabled(false);
                    Actions[7]->setEnabled(false);
                    Actions[8]->setEnabled(false);
                    for(int i = 0;i<currentTruss->v_joint_ptr.size();i++){
                        if(itemList.at(0)->pos() == currentTruss->v_joint_ptr[i]->pos()){
                            selectedJoint1 = i;
                            for(int j = 0;j<currentTruss->v_joint_ptr.size();j++){
                                if(itemList.at(1)->pos() == currentTruss->v_joint_ptr[j]->pos()){
                                    selectedJoint2 = j;
                                    break;
                                }
                            }
                            break;
                        }
                    }
                }
            }
            else{
                Actions[0]->setEnabled(false);
                Actions[1]->setEnabled(false);
                Actions[2]->setEnabled(false);
                Actions[4]->setEnabled(false);
                Actions[5]->setEnabled(false);
                Actions[7]->setEnabled(false);
                Actions[8]->setEnabled(false);
            }
        }
        else{
            Actions[0]->setEnabled(false);
            Actions[1]->setEnabled(false);
            Actions[2]->setEnabled(false);
            Actions[4]->setEnabled(false);
            Actions[5]->setEnabled(false);
            Actions[7]->setEnabled(false);
            Actions[8]->setEnabled(false);
        }
    }

     QGraphicsView::mousePressEvent(event);
}

void myGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QPoint point = event->pos();
    emit mouseMoveSignal(point);
    QGraphicsView::mouseMoveEvent(event);
}

void myGraphicsView::on_action4()
{
    emit selectedJointSignal(selectedJoint1,selectedJoint2);
}

void myGraphicsView::on_action5()
{
    emit selectedEdgeSignal(selectedEdge);
}

void myGraphicsView::on_action8()
{
    emit selectedForceSignal(selectedForce);
}
