#include "config/AppSettings.h"

AppSettings& AppSettings::get() {
	static AppSettings _settings;

	_settings.m_qSettings.sync();

	return _settings;

}
