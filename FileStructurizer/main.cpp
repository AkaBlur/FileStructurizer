#include <iostream>

#include <QCoreApplication>
#include <QtWidgets/QApplication>

#include "config/AppSettings.h"

#include "core/FileStructurizer.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    FileStructurizer w;

    // Initial window configurations
    if (AppSettings::getValue("MainWindow/isMax", false).toBool()) {
        w.showMaximized();

    } else {
        w.show();

    }


    return a.exec();

}
