#include "mainwindow.h"
#include "model.h"
#include <QApplication>
#include <Qpainter>
#include "view.h"
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model model;
    Controller controller;
    MainWindow w;
    w.myController=&controller;
    controller.myModel=&model;
    controller.myWindow=&w;
    w.show();
    return a.exec();
}
