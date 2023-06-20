#include "scrollervolume.h"

#include <math.h>
#include <memory>
#include <string>
#include <iostream>

using namespace ScrollerController;

ScrollerVolume::ScrollerVolume()
{
    try
    {
        init();
        getVolume();
    }
    catch (std::string e)
    {
        std::cout << "SystemVolume init error: " << e << std::endl;
    }
    catch (...)
    {
    }
}

ScrollerVolume::~ScrollerVolume()
{
    close();
}

void ScrollerVolume::init()
{
    hr = CoInitialize(0);
    hr = CoCreateInstance(
        __uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void **)&pDeviceEnumerator);
    if (FAILED(hr))
    {
        throw "InitException:pDeviceEnumerator is NULL;";
    }
    hr = pDeviceEnumerator->GetDefaultAudioEndpoint(eRender, eMultimedia, &pDevice);
    if (FAILED(hr))
    {
        throw "InitException:pDevice is NULL";
    }
    hr = pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (void **)&pAudioEndpointVolume);
    if (FAILED(hr))
    {
        throw "pDevice->Active";
    }
    hr = pDevice->Activate(__uuidof(IAudioClient), CLSCTX_ALL, NULL, (void **)&pAudioClient);
    if (FAILED(hr))
    {
        throw "pDevice->Active";
    }
}

void ScrollerVolume::close()
{
    if (pAudioClient)
    {
        pAudioClient->Release();
    }
    if (pAudioEndpointVolume)
    {
        pAudioEndpointVolume->Release();
    }
    if (pDevice)
    {
        pDevice->Release();
    }
    if (pDeviceEnumerator)
    {
        pDeviceEnumerator->Release();
    }
    CoUninitialize();
}

void ScrollerVolume::setVolume(int volume)
{
    if ((volume - 100.0f) > 0)
    {
        volume = 100.0f;
    }
    else if (volume < 0)
    {
        volume = 0.0;
    }

    float fVolume = volume / 100.0f;
    hr = pAudioEndpointVolume->SetMasterVolumeLevelScalar(fVolume, &GUID_NULL);
    if (FAILED(hr))
    {
        throw "SetMasterVolumeLevelScalar";
    }
}

int ScrollerVolume::getVolume()
{
    float volume;
    hr = pAudioEndpointVolume->GetMasterVolumeLevelScalar(&volume);
    if (FAILED(hr))
    {
        throw "getVolume() throw Exception";
    }
    return (int)round(volume * 100.0);
}

void ScrollerVolume::mute()
{
    hr = pAudioEndpointVolume->SetMute(TRUE, NULL);
    if (FAILED(hr))
    {
        throw "mute() throw Exception";
    }
}

void ScrollerVolume::unMute()
{
    hr = pAudioEndpointVolume->SetMute(FALSE, NULL);
    if (FAILED(hr))
    {
        throw "unMute() throw Exception";
    }
}
