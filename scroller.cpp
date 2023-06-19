#include "scroller.h"

#include <QWheelEvent>
#include <QAudioOutput>
#include <QHBoxLayout>

using namespace scroller;

Scroller::Scroller(QWidget *parent) : QWidget(parent), scroller_colume_(new ScrollerController::ScrollerVolume())
{
    initUi();
}

void Scroller::initUi()
{
    resize(270, 80);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_StyledBackground);
    // setAttribute(Qt::WA_TranslucentBackground);

    QHBoxLayout *main_h_lyt = new QHBoxLayout();
    ui_.volume_pbt = new QPushButton(tr("Volumn"));
    ui_.volume_pbt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    ui_.light_pbt = new QPushButton(tr("Brightness"));
    ui_.light_pbt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    ui_.other_pbt = new QPushButton("");
    ui_.other_pbt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    main_h_lyt->addWidget(ui_.volume_pbt);
    main_h_lyt->addWidget(ui_.light_pbt);
    main_h_lyt->addWidget(ui_.other_pbt);

    main_h_lyt->setContentsMargins(5, 3, 5, 3);

    setLayout(main_h_lyt);

    // setContentsMargins(10, 5, 10, 5);
}

void Scroller::wheelEvent(QWheelEvent *e)
{

    QPoint angleDelta = e->angleDelta();
    int deltaY = angleDelta.y();
    if (deltaY > 0)
    {
        setVoice(100);
    }
    else
    {
        setVoice(0);
    }
}

void Scroller::setVoice(int volumn)
{
    scroller_colume_->SetVolume(volumn);
}