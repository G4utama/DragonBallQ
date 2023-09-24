#include <QApplication>
#include <QFile>
#include <QString>
#include "View/MainWindow.h"
#include "Character/CharacterSet.h"

int main(int argc, char* argv[]){
    srand(time(nullptr));

    CharacterSet saiyajin;
    CharacterSet enemy;
    
    //QFile file("style.qss");
    //file.open(QFile::ReadOnly);
    //QString style=file.readAll();

    QApplication app(argc, argv);
    //app.setStyleSheet(style);

    MainWindow mainWindow(saiyajin, enemy);
    mainWindow.resize(1020, 680);
    mainWindow.setMinimumSize(1020, 680);
    //mainWindow.setStyleSheet("background-image:url(Artwork/skull.png)");
    //mainWindow.setStyleSheet("background-color:green;");
    mainWindow.show();
    return app.exec();
}