#include <QtWidgets/QApplication>

#include "FileStructurizer.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    FileStructurizer w;
    w.show();
    return a.exec();

}
