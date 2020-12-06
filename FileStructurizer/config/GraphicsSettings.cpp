#include "config/AppSettings.h"
#include "config/GraphicsSettings.h"

GraphicsSettings::GraphicsSettings() {
	// Graphics_FolderTopRect
	m_folderTopRect();
	// Graphics_FolderText
	m_folderText();
	// Graphics_FolderShadowRect
	m_folderShadowRect();

}

GraphicsSettings& GraphicsSettings::get() {
	static GraphicsSettings _settings;

	return _settings;

}

GraphicsSettings::DataRectangle& GraphicsSettings::m_getRectSettings(GraphicsSettings::RectangleObjects object) {
	return m_settingsRect[object];

}

GraphicsSettings::DataText& GraphicsSettings::m_getTextSettings(GraphicsSettings::TextObjects object) {
	return m_settingsText[object];

}

// Setup functions for the individual objects
void GraphicsSettings::m_folderTopRect() {
	DataRectangle data;

	data.pen = QPen(           QColor(AppSettings::getNewValue("Graphics_FolderTopRect/PenColor", QColorConstants::DarkGray.rgba()).toUInt()),
		                              AppSettings::getNewValue("Graphics_FolderTopRect/PenWidth", 10).toFloat(),
		static_cast<Qt::PenStyle>    (AppSettings::getNewValue("Graphics_FolderTopRect/PenStyle", (int) Qt::SolidLine).toInt()),
		static_cast<Qt::PenCapStyle> (AppSettings::getNewValue("Graphics_FolderTopRect/PenCapStyle", (int) Qt::RoundCap).toInt()),
		static_cast<Qt::PenJoinStyle>(AppSettings::getNewValue("Graphics_FolderTopRect/PenJoinStyle", (int) Qt::RoundJoin).toInt()));
	
	data.brush = QBrush(            AppSettings::getNewValue("Graphics_FolderTopRect/BrushColor", QColorConstants::DarkGray.rgba()).toUInt(),
		static_cast<Qt::BrushStyle>(AppSettings::getNewValue("Graphics_FolderTopRect/BrushStyle", (int) Qt::SolidPattern).toInt()));

	m_settingsRect.insert(GraphicsSettings::FolderTopRect, data);

}

void GraphicsSettings::m_folderShadowRect() {
	DataRectangle data;
	
	QRgb darkerGray = 0xFF282828;

	data.pen = QPen(           QColor(AppSettings::getNewValue("Graphics_FolderShadowRect/PenColor", darkerGray).toUInt()),
		                              AppSettings::getNewValue("Graphics_FolderShadowRect/PenWidth", 10).toFloat(),
		static_cast<Qt::PenStyle>    (AppSettings::getNewValue("Graphics_FolderShadowRect/PenStyle", (int) Qt::SolidLine).toInt()),
		static_cast<Qt::PenCapStyle> (AppSettings::getNewValue("Graphics_FolderShadowRect/PenCapStyle", (int) Qt::RoundCap).toInt()),
		static_cast<Qt::PenJoinStyle>(AppSettings::getNewValue("Graphics_FolderShadowRect/PenJoinStyle", (int) Qt::RoundJoin).toInt()));

	data.brush = QBrush(            AppSettings::getNewValue("Graphics_FolderShadowRect/BrushColor", darkerGray).toUInt(),
		static_cast<Qt::BrushStyle>(AppSettings::getNewValue("Graphics_FolderShadowRect/BrushStyle", (int) Qt::SolidPattern).toInt()));

	m_settingsRect.insert(GraphicsSettings::FolderShadowRect, data);

}

void GraphicsSettings::m_folderText() {
	DataText data;

	data.brush = QBrush(     QColor(AppSettings::getNewValue("Graphics_FolderText/BrushColor", QColorConstants::Black.rgba()).toUInt()),
		static_cast<Qt::BrushStyle>(AppSettings::getNewValue("Graphics_FolderText/BrushStyle", (int) Qt::SolidPattern).toInt()));

	data.margins.top    = AppSettings::getNewValue("Graphics_FolderText/MarginTop", 10).toInt();
	data.margins.bottom = AppSettings::getNewValue("Graphics_FolderText/MarginBottom", 10).toInt();
	data.margins.left   = AppSettings::getNewValue("Graphics_FolderText/MarginLeft", 10).toInt();
	data.margins.right  = AppSettings::getNewValue("Graphics_FolderText/MarginRight", 10).toInt();

	data.fontSize = AppSettings::getNewValue("Graphics_FolderText/FontSize", 12).toInt();

	m_settingsText.insert(GraphicsSettings::FolderText, data);

}