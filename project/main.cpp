#include <QtGui>

#include "windowCalendar.h"

int main(int argv, char *args[])
{
    QApplication app(argv, args);
    windowCalendar window;
    window.show();
    return app.exec();
}
