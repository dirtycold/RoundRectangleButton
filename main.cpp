#include "roundrectanglebutton.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RoundRectangleButton w;
    w.setRoundRadius (70);
    w.setColor (Qt::darkBlue);
    w.setTextColor (Qt::white);
    w.setText ("Round\nRectangle\nButton");
    w.resize (160, 120);
    w.show();

    QObject::connect (&w, &RoundRectangleButton::clicked, &a, &QApplication::quit);

    return a.exec();
}
