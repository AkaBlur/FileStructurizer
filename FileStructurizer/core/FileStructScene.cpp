#include <QGraphicsItem>

#include "core/FileStructScene.h"

#include "graphics/RectFolder.h"

FileStructScene::FileStructScene() : QGraphicsScene() {

}

void FileStructScene::setTestScene(int scene) {
	m_removeAllItems();

	int width = 200;
	int height = 120;

	switch (scene) {
		case 0:
			// Text button
			m_addItem("root", new RectFolder(0, 0, width, height, "Hello"));

			break;

		case 1:
			// One Rect button

			break;

		case 2:
			// Many rect button

			break;

		default:
			break;

	}

}

void FileStructScene::keyPressEvent(QKeyEvent* event) {
	if (event->key() == Qt::Key_R) {
		QHash<QString, QGraphicsItemGroup*>::const_iterator it;

		for (it = this->m_sceneItems.constBegin(); it != this->m_sceneItems.constEnd(); it++) {
			QGraphicsItem* item = it.value();
			item->setRotation(item->rotation() + 10);

		}


	}

}

void FileStructScene::m_addItem(QString text, QGraphicsItemGroup* item) {
	if (m_sceneItems.isEmpty()) {
		emit centerOnItem(item);

	}

	this->m_sceneItems.insert(text, item);
	this->addItem(item);

}

void FileStructScene::m_removeAllItems() {
	QHash<QString, QGraphicsItemGroup*>::const_iterator it;

	for (it = m_sceneItems.constBegin(); it != m_sceneItems.constEnd(); it++) {
		this->removeItem(it.value());

	}

	m_sceneItems.clear();

}