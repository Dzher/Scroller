#include "scrollercontrolregion.h"
#include <QDebug>

#include <QWheelEvent>

using namespace scroller;

ScrollerControlRegion::ScrollerControlRegion(const QString &text, int original, QWidget *parent) : QPushButton(parent), current_value_(original) {}

void ScrollerControlRegion::wheelEvent(QWheelEvent *e)
{

    QPoint angleDelta = e->angleDelta();
    // TODO: 30 is a temp delta value
    int deltaY = angleDelta.y() / 30;
    int new_value;
    if (deltaY > 0)
    {
        rotation_ = true;
        new_value = current_value_ + deltaY > 100 ? 100 : current_value_ + deltaY;
    }
    else
    {
        rotation_ = false;
        new_value = current_value_ + deltaY < 0 ? 0 : current_value_ + deltaY;
    }
    cb_(new_value);
    current_value_ = new_value;
}

void ScrollerControlRegion::initUi()
{
}

bool ScrollerControlRegion::getRotation()
{
    return rotation_;
}

int ScrollerControlRegion::getCurrentValue()
{
    return current_value_;
}

void ScrollerControlRegion::setCurrentValue(int value)
{
    current_value_ = value;
}

void ScrollerControlRegion::setCallbackFunc(const ScrCb &cb)
{
    cb_ = cb;
}