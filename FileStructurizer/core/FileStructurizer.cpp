#include <iostream>

#include <QWheelEvent>

#include "FileStructurizer.h"

FileStructurizer::FileStructurizer(QWidget *parent)
    : QMainWindow(parent) {
    ui.setupUi(this);

    //Init the file view and add it as widget
    m_fileView = std::make_unique<FileStructView>(&m_fileScene);
    ui.horizontalLayout->addWidget(m_fileView.get());

    //Init connections
    connect(ui.pushButton_Empty, &QPushButton::clicked, this, &FileStructurizer::pushButton_Empty_Clicked);
    connect(ui.pushButton_Text, &QPushButton::clicked, this, &FileStructurizer::pushButton_Text_Clicked);
    connect(ui.pushButton_oneRect, &QPushButton::clicked, this, &FileStructurizer::pushButton_OneRect_Clicked);
    connect(ui.pushButton_ManyRect, &QPushButton::clicked, this, &FileStructurizer::pushButton_ManyRect_Clicked);

    connect(this, &FileStructurizer::setTestScene, &m_fileScene, &FileStructScene::setTestScene);

}

void FileStructurizer::pushButton_Empty_Clicked() {
    emit setTestScene(-1);

}

void FileStructurizer::pushButton_Text_Clicked() {
    emit setTestScene(0);

}

void FileStructurizer::pushButton_OneRect_Clicked() {
    emit setTestScene(1);

}

void FileStructurizer::pushButton_ManyRect_Clicked() {
    emit setTestScene(2);

}
