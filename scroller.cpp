#include "scroller.h"

#include <QAudioOutput>
#include <QHBoxLayout>

using namespace scroller;

Scroller::Scroller(QWidget *parent) : QWidget(parent), scroller_colume_(new ScrollerController::ScrollerVolume())
{
    initUi();
    configController();
}

void Scroller::initUi()
{
    resize(270, 80);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_StyledBackground);
    // setAttribute(Qt::WA_TranslucentBackground);

    QHBoxLayout *main_h_lyt = new QHBoxLayout();
    ui_.volume_rgn = new ScrollerControlRegion(tr("Volumn"));
    ui_.volume_rgn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    ui_.light_rgn = new ScrollerControlRegion(tr("Brightness"));
    ui_.light_rgn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    ui_.other_rgn = new ScrollerControlRegion("");
    ui_.other_rgn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    main_h_lyt->addWidget(ui_.volume_rgn);
    main_h_lyt->addWidget(ui_.light_rgn);
    main_h_lyt->addWidget(ui_.other_rgn);

    main_h_lyt->setContentsMargins(5, 3, 5, 3);

    setLayout(main_h_lyt);
}

void Scroller::configController()
{
    assert(ui_.volume_rgn);
    assert(ui_.light_rgn);

    ui_.volume_rgn->setCurrentValue(scroller_colume_->getVolume());
    ScrCb volumn_cb = [this](int volume)
    {
        scroller_colume_->setVolume(volume);
    };
    ui_.volume_rgn->setCallbackFunc(volumn_cb);
}