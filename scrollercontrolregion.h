#include <QtWidgets/QSlider>
#include <functional>

#ifndef _SCROLLERCONTROLREGION_H_
#define _SCROLLERCONTROLREGION_H_

namespace scroller
{
    using ScrCb = std::function<void(int)>;
    class ScrollerControlRegion : public QSlider
    {
    public:
        explicit ScrollerControlRegion(const QString &text, int original = 0, QWidget *parent = nullptr);

        void setWheelCb(const ScrCb &cb);
        void setRightCb(const ScrCb &cb);
        void setCurrentValue(int value);
        int getCurrentValue();

        bool getRotation();

    private:
        void initUi();
        void wheelEvent(QWheelEvent *e) override;
        bool event(QEvent *e) override;

    private:
        int current_value_ = 0;
        bool mute_ = false;
        bool rotation_;
        ScrCb wheel_cb_;
        ScrCb right_cb_;
    };
}

#endif //_SCROLLERCONTROLREGION_H_