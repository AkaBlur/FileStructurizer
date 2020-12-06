#pragma once

#include <QtWidgets/QMainWindow>

#include <ui_FileStructurizer.h>

#include "core/FileStructScene.h"
#include "core/FileStructView.h"

class FileStructurizer : public QMainWindow {
    Q_OBJECT

public:
    FileStructurizer(QWidget *parent = Q_NULLPTR);
    ~FileStructurizer();

private:
    Ui::FileStructurizerClass ui;

    // Main file view
    std::unique_ptr<FileStructView> m_fileView;
    // Main file view scene
    FileStructScene m_fileScene;

signals:
    void setTestScene(int scene);

private slots:
    void pushButton_Empty_Clicked();
    void pushButton_Text_Clicked();
    void pushButton_OneRect_Clicked();
    void pushButton_ManyRect_Clicked();

};
