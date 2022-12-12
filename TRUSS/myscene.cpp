#include "myscene.h"
#include "ui_mainwindow.h"
#include "mygraphicsview.h"
#include <iostream>
#include <string>
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneContextMenuEvent>

myScene::myScene(QObject *parent) : QGraphicsScene(parent)
{
    createActions();
}

void myScene::createActions() {

    menu = new QMenu;


    QAction* addJointAction = menu->addAction("add Joint");
    QAction* addSupportAction = menu->addAction("add Support");
    QAction* deleteJointAction = menu->addAction("delete Joint/Support");
    menu->addSeparator();
    QAction* addEdgeAction = menu->addAction("add Rod");
    QAction* deleteEdgeAction = menu->addAction("delete Rod");
    menu->addSeparator();
    QAction* addForceAction = menu->addAction("add Force");
    QAction* deleteForceAction = menu->addAction("delete Force");

}

void myScene::contextMenuEvent(QGraphicsSceneContextMenuEvent *event) {

    menu->exec(event->screenPos());
}


    //Koordinatenpunkt P
void myScene::set_Point(QPointF P){

    Point=P;
}

QPointF myScene::get_Point() {

    return Point;
}
