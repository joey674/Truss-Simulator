#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QContextMenuEvent>
#include <QMenu>

class myScene : public QGraphicsScene
{
public:
    explicit myScene(QObject *parent = nullptr);
    void set_Point(QPointF P);
    void createActions();
    QPointF get_Point();
    QMenu* menu;

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

signals:


private:
    QPointF Point;
};

#endif // MYSCENE_H
