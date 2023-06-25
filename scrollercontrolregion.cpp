#include "scrollercontrolregion.h"
#include <QDebug>

#include <QWheelEvent>

using namespace scroller;

ScrollerControlRegion::ScrollerControlRegion(const QString &text, int original, QWidget *parent) : QSlider(parent), current_value_(original) {}

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
    wheel_cb_(new_value);
    current_value_ = new_value;
    setValue(current_value_);
}

bool ScrollerControlRegion::event(QEvent *e)
{
    if (e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouse_e = static_cast<QMouseEvent *>(e);
        if (mouse_e->button() == Qt::MouseButton::RightButton)
        {
            right_cb_(mute_);
            mute_ = !mute_;
            return QWidget::event(e);
        }
    }
    return QWidget::event(e);
}

void ScrollerControlRegion::initUi()
{
    setOrientation(Qt::Orientation::Vertical);
    setTickPosition(QSlider::TicksLeft);
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

void ScrollerControlRegion::setWheelCb(const ScrCb &cb)
{
    wheel_cb_ = cb;
}

void ScrollerControlRegion::setRightCb(const ScrCb &cb)
{
    right_cb_ = cb;
}