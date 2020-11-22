#include <FileStructurizer.h>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileStructurizer w;
    w.show();
    return a.exec();
}
