#include <QBrush>
#include <QPen>
#include <QFont>

#include "config/GraphicsSettings.h"
#include "graphics/RectFolder.h"

RectFolder::RectFolder(qreal x, qreal y, qreal width, qreal height) {
	m_init(x, y, width, height, "");

}

RectFolder::RectFolder(qreal x, qreal y, qreal width, qreal height, QString folderName) {
	m_init(x, y, width, height,  folderName);

}

void RectFolder::setFolderName(QString folderName) {
	this->m_folderName = folderName;

	m_updateGeometry();

}

void RectFolder::m_init(qreal x, qreal y, qreal width, qreal height, QString folderName) {
	this->m_folderName = folderName;
	this->m_isSelected = false;

	// Shadow of the main rectangle
	int shadowDistPx = 3;
	this->p_folderRectShadow = std::make_shared<QGraphicsRectItem>((x + shadowDistPx), (y + shadowDistPx), width, height);
	p_folderRectShadow->setPen(FS_GRAPHICS_FOLDER_SHADOW_RECT.pen);
	p_folderRectShadow->setBrush(FS_GRAPHICS_FOLDER_SHADOW_RECT.brush);

	this->addToGroup(p_folderRectShadow.get());

	// Main rectangle
	this->p_folderRect = std::make_shared<QGraphicsRectItem>(x, y, width, height);
	p_folderRect->setPen(FS_GRAPHICS_FOLDER_TOP_RECT.pen);
	p_folderRect->setBrush(FS_GRAPHICS_FOLDER_TOP_RECT.brush);

	this->addToGroup(p_folderRect.get());

	// Folder name
	this->p_folderName = std::make_shared<QGraphicsSimpleTextItem>(m_folderName, p_folderRect.get());
	p_folderName->setBrush(FS_GRAPHICS_FOLDER_TEXT.brush);
	p_folderName->setPos(FS_GRAPHICS_FOLDER_TEXT.margins.top, FS_GRAPHICS_FOLDER_TEXT.margins.left);

	QFont folderDescriptFont = p_folderName->font();
	folderDescriptFont.setPointSize(FS_GRAPHICS_FOLDER_TEXT.fontSize);
	p_folderName->setFont(folderDescriptFont);

	this->addToGroup(p_folderName.get());

	m_updateGeometry();

}

void RectFolder::m_updateGeometry() {
	// Get the bounds needed for the text to fit
	QRectF textBounds = p_folderName->boundingRect();
	textBounds.setWidth(textBounds.width() + FS_GRAPHICS_FOLDER_TEXT.margins.right + FS_GRAPHICS_FOLDER_TEXT.margins.left);
	textBounds.setHeight(textBounds.height() + FS_GRAPHICS_FOLDER_TEXT.margins.bottom + FS_GRAPHICS_FOLDER_TEXT.margins.top);

	// Override the width and heigth of the boundary if the text already fits
	if (textBounds.width() < p_folderRect->rect().width()) {
		textBounds.setWidth(p_folderRect->rect().width());

	}

	if (textBounds.height() < p_folderRect->rect().height()) {
		textBounds.setHeight(p_folderRect->rect().height());

	}

	// Set the folder names position
	p_folderName->setPos(FS_GRAPHICS_FOLDER_TEXT.margins.top, FS_GRAPHICS_FOLDER_TEXT.margins.left);

	// Set the rectangle size
	p_folderRect->setRect(textBounds);

}