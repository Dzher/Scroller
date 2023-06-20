#include <windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <audioclient.h>

#ifndef _SCROLLERVOLUME_H_
#define _SCROLLERVOLUME_H_

namespace ScrollerController
{

    class ScrollerVolume
    {
    public:
        explicit ScrollerVolume();
        virtual ~ScrollerVolume();

        void mute();
        void unMute();
        void setVolume(int volume);
        int getVolume();

    private:
        void init();
        void close();

    private:
        HRESULT hr;
        IMMDeviceEnumerator *pDeviceEnumerator = 0;
        IMMDevice *pDevice = 0;
        IAudioEndpointVolume *pAudioEndpointVolume = 0;
        IAudioClient *pAudioClient = 0;
    };

} // namespace ScrollerController

#endif //_SCROLLERVOLUME_H_