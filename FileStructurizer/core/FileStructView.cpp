#include <iostream>

#include <QApplication>
#include <QGraphicsSceneEvent>

#include "FileStructView.h"

FileStructView::FileStructView(FileStructScene* scene) : m_scene(scene) {
    //Init the scene
    this->setScene(m_scene);
    //Filter events towards the scene
    m_scene->installEventFilter(this);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Initialize connections
    connect(m_scene, &FileStructScene::centerOnItem, this, &FileStructView::centerOnItem);

}

bool FileStructView::eventFilter(QObject* watched, QEvent* event) {
    if (watched != m_scene) return false;

    //Receive every possible combination of mouse button presses
    //Normal button press and dblclick events
    if ((event->type() == QEvent::MouseButtonPress) ||
        (event->type() == QEvent::MouseButtonDblClick)) {
        QMouseEvent* mEvent = static_cast<QMouseEvent*>(event);

        //Forward if not left mouse button
        if (mEvent->button() != Qt::LeftButton) return false;

        //Suppress if shift is pressed, then initiate the drag mode
        if (mEvent->modifiers() & Qt::ShiftModifier) {
            this->setDragMode(QGraphicsView::ScrollHandDrag);

            return true;

        }

    }

    //Mouse button press and dblclick inside the graphics scene
    if ((event->type() == QEvent::GraphicsSceneMousePress) ||
        (event->type() == QEvent::GraphicsSceneMouseDoubleClick)) {
        QGraphicsSceneMouseEvent* mEvent = static_cast<QGraphicsSceneMouseEvent*>(event);

        //Forward if not left mouse button
        if (mEvent->button() != Qt::LeftButton) return false;

        //Suppress if shift is pressed, then initiate the drag mode
        if (mEvent->modifiers() & Qt::ShiftModifier) {
            this->setDragMode(QGraphicsView::ScrollHandDrag);

            return true;

        }

    }

    //Mouse button release events
    if ((event->type() == QEvent::MouseButtonRelease) ||
        (event->type() == QEvent::GraphicsSceneMouseRelease)) {
        QMouseEvent* mEvent = static_cast<QMouseEvent*>(event);

        //Forward if not left mouse button
        if (mEvent->button() == Qt::LeftButton) return false;

        //Suppress if shift is pressed and turn off drag mode
        if (mEvent->modifiers() & Qt::ShiftModifier) {
            this->setDragMode(QGraphicsView::NoDrag);
            return true;

        }

    }

    //Key release events for the shift key
    if (event->type() == QEvent::KeyRelease) {
        QKeyEvent* kEvent = static_cast<QKeyEvent*>(event);

        if (kEvent->key() == Qt::Key_Shift) {
            this->setDragMode(QGraphicsView::NoDrag);

            return true;

        }

    }

    return false;

}

void FileStructView::wheelEvent(QWheelEvent* event) {
    bool isForward = event->angleDelta().y() >= 0;
    bool isShiftPressed = event->modifiers() & Qt::ShiftModifier;
    //Get the current zoom transform element of the transformation matrix to check the zoomed value
    qreal scaleTransform = this->transform().m11();

    if (isForward && isShiftPressed && (scaleTransform * VIEW_ZOOM_IN < VIEW_MAXZOOM)) {
        this->scale(VIEW_ZOOM_IN, VIEW_ZOOM_IN);

    } else if (!isForward && isShiftPressed && (scaleTransform * VIEW_ZOOM_OUT > VIEW_MINZOOM)) {
        this->scale(VIEW_ZOOM_OUT, VIEW_ZOOM_OUT);

    }

}

void FileStructView::centerOnItem(QGraphicsItem* item) {
    this->centerOn(item);

}