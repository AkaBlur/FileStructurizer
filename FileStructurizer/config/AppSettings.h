#pragma once

#include <QSettings>

class AppSettings {
public:
	// Get the singleton instance
	static AppSettings& get();

	// Get the status
	static QSettings::Status getStatus() { return get().m_qSettings.status();  }
	// Retrieve a value
	static QVariant getValue(const QString& name, const QVariant& default = QVariant()) { return get().m_qSettings.value(name, default); };
	// Retrieve a value and set it if it doesn't exist
	static QVariant getNewValue(const QString& name, const QVariant& value) { return get().m_getNewValue(name, value); };
	// Set a value with a specific name
	static void setValue(const QString& name, const QVariant& value) { get().m_qSettings.setValue(name, value); };
	// Set a value if the key does not exist
	static void setNewValue(const QString& name, const QVariant& value) { get().m_setNewValue(name, value); };

	AppSettings(const AppSettings& copy) = delete;
	AppSettings(AppSettings&& move) = delete;

private:
	AppSettings() : m_qSettings(QSettings::IniFormat, QSettings::UserScope, "AkaBlur", "File Structurizer") {};

	// Main settings .INI
	QSettings m_qSettings;

	QVariant m_getNewValue(const QString& name, const QVariant& value);
	void m_setNewValue(const QString& name, const QVariant& value);

};