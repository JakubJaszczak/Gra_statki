#include "view.h"
#include <QPainter>
View::View(MainWindow* window_param)
{window=window_param;
    QPaintEvent *event;
    window->color=Qt::blue;
    window->paintEvent(event);

}
