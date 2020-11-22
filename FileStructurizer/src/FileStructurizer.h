#pragma once

#include <QtWidgets/QMainWindow>
#include <ui_FileStructurizer.h>

class FileStructurizer : public QMainWindow
{
    Q_OBJECT

public:
    FileStructurizer(QWidget *parent = Q_NULLPTR);

private:
    Ui::FileStructurizerClass ui;
};
