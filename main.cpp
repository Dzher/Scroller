#include "scroller.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    scroller::Scroller *scroller_wgt = new scroller::Scroller();
    scroller_wgt->show();
    app.exec();
}
