#include <iostream>

#include <QGraphicsItem>

#include "FileStructScene.h"

FileStructScene::FileStructScene() : QGraphicsScene() {

}

void FileStructScene::setTestScene(int scene) {
	m_removeAllItems();

	int width = 100;
	int height = 150;

	switch (scene) {
		case 0:
			m_addItem("Text1", new TestText("Hello"));

			break;

		case 1:
			m_addItem("Rect1", new TestRect(10, 10, 200, 400));

			break;

		case 2:
			for (int i = 0; i < 10; i++) {
				QString rect = "Rect";
				rect.append(std::to_string(i).c_str());

				m_addItem(rect, new TestRect((10 + width * i * 1.5), (10 + height * i * 1.25), width, height));

			}

			break;

		default:
			break;

	}

}

void FileStructScene::m_addItem(QString text, QGraphicsItem* item) {
	if (m_sceneItems.isEmpty()) {
		emit centerOnItem(item);

	}

	this->m_sceneItems.insert(text, item);
	std::cout << "Added: " << text.toStdString() << std::endl;
	this->addItem(item);

}

void FileStructScene::m_removeAllItems() {
	QHash<QString, QGraphicsItem*>::const_iterator it;

	for (it = m_sceneItems.constBegin(); it != m_sceneItems.constEnd(); it++) {
		this->removeItem(it.value());
		std::cout << "Removed: " << it.key().toStdString() << std::endl;

	}

	m_sceneItems.clear();

}

TestText::TestText(QString text) : QGraphicsTextItem(text) {

}

void TestText::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent) {
	if (mouseEvent->button() == Qt::LeftButton) {
		this->setDefaultTextColor(Qt::red);

	}

}

void TestText::mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent) {
	if (mouseEvent->button() == Qt::LeftButton) {
		this->setDefaultTextColor(Qt::black);

	}

}

TestRect::TestRect(int x, int y, int width, int height) : QGraphicsRectItem(x, y, width, height) {
	this->setBrush(QBrush(Qt::black, Qt::SolidPattern));

}

void TestRect::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent) {
	if (mouseEvent->button() == Qt::LeftButton) {
		this->setBrush(QBrush(Qt::red, Qt::SolidPattern));

	}

}

void TestRect::mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent) {
	if (mouseEvent->button() == Qt::LeftButton) {
		this->setBrush(QBrush(Qt::black, Qt::SolidPattern));

	}

}