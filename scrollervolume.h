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

        void Mute();
        void UnMute();
        void SetVolume(int volume);
        int GetVolume();

    private:
        void Init();
        void Close();

    private:
        HRESULT hr;
        IMMDeviceEnumerator *pDeviceEnumerator = 0;
        IMMDevice *pDevice = 0;
        IAudioEndpointVolume *pAudioEndpointVolume = 0;
        IAudioClient *pAudioClient = 0;
    };

} // namespace ScrollerController

#endif //_SCROLLERVOLUME_H_