#ifndef _SCROLLER_LIGHT_H_
#define _SCROLLER_LIGHT_H_

namespace ScrollerController
{
    class ScrollerLight
    {
    public:
        explicit ScrollerLight();
        virtual ~ScrollerLight();

        void setBrightness(int value);
    };
}

#endif //_SCROLLER_LIGHT_H_