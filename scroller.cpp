#include "scroller.h"

#include <QWheelEvent>
#include <QAudioOutput>

using namespace scroller;

Scroller::Scroller(QWidget *parent) : QWidget(parent)
{
    initUi();
}

void Scroller::initUi()
{
    resize(270, 80);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_StyledBackground);
    // setAttribute(Qt::WA_TranslucentBackground);
}

void Scroller::wheelEvent(QWheelEvent *e)
{

    QPoint angleDelta = e->angleDelta();
    int deltaY = angleDelta.y();
    if (deltaY > 0)
    {
        setVoice(current_voice_ + deltaY / 120);
    }
    else
    {
        setVoice(current_voice_ - deltaY / 120);
    }
}

void Scroller::setVoice(double percentage)
{
}