#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>

#include <QWheelEvent>

#include "FileStructScene.h"

//Zooming modifiers for the view
#define VIEW_ZOOM_IN 1.25f
#define VIEW_ZOOM_OUT 0.8f
//Zooming boundaries
#define VIEW_MAXZOOM 10.0f
#define VIEW_MINZOOM 0.5f

class FileStructView : public QGraphicsView {
	Q_OBJECT

public:
	//Main constructor with scene to show
	FileStructView(FileStructScene* scene);

protected:
	bool eventFilter(QObject* watched, QEvent* event) override;

	void wheelEvent(QWheelEvent* event) override;

private:
	//Main scene pointer
	FileStructScene* m_scene;

private slots:
	void centerOnItem(QGraphicsItem* item);

};