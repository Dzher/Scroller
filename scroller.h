#include <QtWidgets/QtWidgets>
#include <QtWidgets/QPushButton>
#include "scrollervolume.h"

#ifndef _SCROLLER_H_
#define _SCROLLER_H_

namespace scroller
{
    class Scroller : public QWidget
    {
    public:
        Scroller(QWidget *parent = nullptr);
        ~Scroller() = default;

    private:
        void initUi();
        void wheelEvent(QWheelEvent *e) override;
        void setVoice(int volumn);

    private:
        struct UI
        {
            QPushButton *volume_pbt;
            QPushButton *light_pbt;
            QPushButton *other_pbt;
        } ui_;

        ScrollerController::ScrollerVolume *scroller_colume_;
        double current_voice_;
    };
}

#endif