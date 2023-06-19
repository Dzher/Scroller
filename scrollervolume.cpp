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
        Init();
        GetVolume();
    }
    catch (std::string e)
    {
        std::cout << "SystemVolume Init error: " << e << std::endl;
    }
    catch (...)
    {
    }
}

ScrollerVolume::~ScrollerVolume()
{
    Close();
}

void ScrollerVolume::Init()
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

void ScrollerVolume::Close()
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

void ScrollerVolume::SetVolume(int volume)
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

int ScrollerVolume::GetVolume()
{
    float volume;
    hr = pAudioEndpointVolume->GetMasterVolumeLevelScalar(&volume);
    if (FAILED(hr))
    {
        throw "getVolume() throw Exception";
    }
    return (int)round(volume * 100.0);
}

void ScrollerVolume::Mute()
{
    hr = pAudioEndpointVolume->SetMute(TRUE, NULL);
    if (FAILED(hr))
    {
        throw "Mute() throw Exception";
    }
}

void ScrollerVolume::UnMute()
{
    hr = pAudioEndpointVolume->SetMute(FALSE, NULL);
    if (FAILED(hr))
    {
        throw "UnMute() throw Exception";
    }
}
