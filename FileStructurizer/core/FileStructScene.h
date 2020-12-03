#pragma once

#include <QGraphicsScene>
#include <QGraphicsSceneEvent>
#include <QGraphicsItem>

class TestText;
class TestRect;

class FileStructScene : public QGraphicsScene {
	Q_OBJECT

public:
	FileStructScene();

private:
	//Storage for all items in the scene
	QHash<QString, QGraphicsItem*> m_sceneItems;

	//Add a new item group
	void m_addItem(QString name, QGraphicsItem* item);
	void m_removeAllItems();

signals:
	void centerOnItem(QGraphicsItem* item);

public slots:
	void setTestScene(int scene);

};

class TestText : public QGraphicsTextItem {
public:
	TestText(QString text);

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

};

class TestRect : public QGraphicsRectItem {
public:
	TestRect(int x, int y, int width, int height);

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent) override;

};