#include <QtWidgets/QtWidgets>
#include <QtWidgets/QLabel>

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
        void setVoice(double percentage);

    private:
        // struct UI
        // {
        // } ui_;
        double current_voice_;
    };
}

#endif