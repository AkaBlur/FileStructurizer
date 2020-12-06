#pragma once

#include <QGraphicsScene>
#include <QGraphicsSceneEvent>
#include <QGraphicsItemGroup>

#include <QKeyEvent>

class TestText;
class TestRect;

class FileStructScene : public QGraphicsScene {
	Q_OBJECT

public:
	FileStructScene();

protected:
	void keyPressEvent(QKeyEvent* event) override;

private:
	// Storage for all items in the scene
	QHash<QString, QGraphicsItemGroup*> m_sceneItems;

	// Add a new item group
	void m_addItem(QString name, QGraphicsItemGroup* item);
	void m_removeAllItems();

signals:
	void centerOnItem(QGraphicsItemGroup* item);

public slots:
	void setTestScene(int scene);

};