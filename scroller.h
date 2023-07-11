#include <QtWidgets/QtWidgets>
#include "scrollercontrolregion.h"
#include "scrollervolume.h"
#include "scrollerlight.h"


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
        void configController();

    private:
        struct UI
        {
            ScrollerControlRegion *volume_rgn;
            ScrollerControlRegion *light_rgn;
            ScrollerControlRegion *other_rgn;
        } ui_;

        ScrollerController::ScrollerVolume *scroller_colume_;
        ScrollerController::ScrollerLight* scroller_light_;
    };
}

#endif