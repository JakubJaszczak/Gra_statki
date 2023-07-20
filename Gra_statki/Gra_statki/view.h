#ifndef VIEW_H
#define VIEW_H
#include "mainwindow.h"
#include <QPainter>
class View
{
public:
    View(MainWindow* window_param);
    MainWindow* window;

};

#endif // VIEW_H
