#pragma once

#include <QGraphicsItemGroup>
#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>

class RectFolder : public QGraphicsItemGroup {
public:
	RectFolder(qreal x, qreal y, qreal width, qreal height);
	RectFolder(qreal x, qreal y, qreal width, qreal height, QString folderName);

	// Set the main folder name
	void setFolderName(QString folderName);

private:
	// Init
	void m_init(qreal x, qreal y, qreal width, qreal height, QString folderName);

	// Update the boundaries after the graphical layout changed
	void m_updateGeometry();

	// Main folder rect item
	std::shared_ptr<QGraphicsRectItem> p_folderRect;
	// Shadow of that rectangle
	std::shared_ptr<QGraphicsRectItem> p_folderRectShadow;

	// Main folder name and graphical item
	QString m_folderName;
	std::shared_ptr<QGraphicsSimpleTextItem> p_folderName;

	// Selection value
	bool m_isSelected;

};