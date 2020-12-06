#include "config/AppSettings.h"

AppSettings& AppSettings::get() {
	static AppSettings _settings;

	_settings.m_qSettings.sync();

	return _settings;

}

QVariant AppSettings::m_getNewValue(const QString& name, const QVariant& value) {
	if (!get().m_qSettings.contains(name)) {
		AppSettings::setValue(name, value);

	}

	return AppSettings::getValue(name, value);

}

void AppSettings::m_setNewValue(const QString& name, const QVariant& value) {
	if (!get().m_qSettings.contains(name)) {
		get().setValue(name, value);

	}

}
