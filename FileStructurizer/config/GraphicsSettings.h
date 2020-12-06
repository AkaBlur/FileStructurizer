#pragma once

// Graphics settings for individual graphical objects
// All setting are stored in the main config .INI.
// To create a settings object for an existing graphical object
// which has a type of QGraphicsItem, like rectangle, text, line, etc.:
//
// - Create an identifier in the corresponding enum
// - Ensure there is a data type (struct) for the data
// - Ensure there is a data hash for the data
// - Provide a private setup function for the settings
//    - Create a data structure
//    - Set all data as AppSettings::setNewValue(...) and provide a default
//    - Write the data in the corresponding data hash
// - Append the setup function in the constructor of GraphicsSettings
// - (OPTIONAL) Create a macro for easier accessing the settings of a specific object

#include <QBrush>
#include <QColor>
#include <QHash>
#include <QPen>

// Macros for easier accessing the individual settings objects
#define FS_GRAPHICS_FOLDER_TOP_RECT GraphicsSettings::getRectangleSettings(GraphicsSettings::FolderTopRect)
#define FS_GRAPHICS_FOLDER_SHADOW_RECT GraphicsSettings::getRectangleSettings(GraphicsSettings::FolderShadowRect)
#define FS_GRAPHICS_FOLDER_TEXT GraphicsSettings::getTextSettings(GraphicsSettings::FolderText)

class GraphicsSettings {
public:
	// Enum for the objects which are contained in the settings
	// Name of the settings object given as comment
	// Rectangle objects
	enum RectangleObjects {
		// Graphics_FolderTopRect
		FolderTopRect,
		// Graphics_FolderShadowRect
		FolderShadowRect

	};

	// Simple text objects
	enum TextObjects {
		// Graphics_FolderText
		FolderText

	};

	// Data struct for a rectangle
	struct DataRectangle {
		// Outer line
		QPen pen;

		// Brush for filling
		QBrush brush;


	};

	// Data struct for a simple text object
	struct DataText {
		// Brush for the text 
		// QPen could also be possible but a text outline is not needed and costs too much performance
		QBrush brush;

		// Main margins for the outline of the text
		// Don't set it smaller than half of the outer pen thickness of the containing object
	    // otherwise the contents of the rectangle will glitch in the outer pen line.
		struct Margins {
			int top;
			int bottom;
			int left;
			int right;

		} margins;

		// Font size in pt
		int fontSize;

	};

	// Get singleton instance
	static GraphicsSettings& get();

	// Return rectangle settings for a given object
	static GraphicsSettings::DataRectangle& getRectangleSettings(GraphicsSettings::RectangleObjects object) { return get().m_getRectSettings(object); };
	// Return the text settings for a given object
	static GraphicsSettings::DataText& getTextSettings(GraphicsSettings::TextObjects object) { return get().m_getTextSettings(object); };

	GraphicsSettings(const GraphicsSettings& gs) = delete;
	GraphicsSettings(GraphicsSettings&& gs) = delete;

private:
	GraphicsSettings();

	// Singleton
	static GraphicsSettings _settings;

	// Settings hash for rectangles
	QHash<GraphicsSettings::RectangleObjects, DataRectangle> m_settingsRect;
	GraphicsSettings::DataRectangle& m_getRectSettings(GraphicsSettings::RectangleObjects object);

	// Settings hash for text
	QHash<GraphicsSettings::TextObjects, DataText> m_settingsText;
	GraphicsSettings::DataText& m_getTextSettings(GraphicsSettings::TextObjects object);

	// Setup functions for the individual elements
	// Root folder top rectangle
	void m_folderTopRect();
	// Root folder shadow rectangle
	void m_folderShadowRect();
	// Text for root folder
	void m_folderText();

};