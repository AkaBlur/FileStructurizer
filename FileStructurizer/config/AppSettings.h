#pragma once

#include <QSettings>

class AppSettings {
public:
	//Get the singleton instance
	static AppSettings& get();

	//Get the status
	static QSettings::Status getStatus() { return get().m_qSettings.status();  }
	//Retrieve a value
	static QVariant getValue(const QString& name, const QVariant& default = QVariant()) { return get().m_qSettings.value(name, default); };
	//Set a value with a specific name
	static void setValue(const QString& name, const QVariant& value) { get().m_qSettings.setValue(name, value); };

	AppSettings(const AppSettings& copy) = delete;
	AppSettings(AppSettings&& move) = delete;

private:
	AppSettings() : m_qSettings(QSettings::IniFormat, QSettings::UserScope, "AkaBlur", "File Structurizer") {};

	QSettings m_qSettings;

};