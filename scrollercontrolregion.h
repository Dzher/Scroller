#include <QtWidgets/QPushButton>
#include <functional>

#ifndef _SCROLLERCONTROLREGION_H_
#define _SCROLLERCONTROLREGION_H_

namespace scroller
{
    using ScrCb = std::function<void(int)>;
    class ScrollerControlRegion : public QPushButton
    {
    public:
        explicit ScrollerControlRegion(const QString &text, int original = 0, QWidget *parent = nullptr);

        void setCallbackFunc(const ScrCb &cb);
        void setCurrentValue(int value);
        int getCurrentValue();

        bool getRotation();

    private:
        void initUi();
        void wheelEvent(QWheelEvent *e) override;

    private:
        int current_value_ = 0;
        bool rotation_;
        ScrCb cb_;
    };
}

#endif //_SCROLLERCONTROLREGION_H_