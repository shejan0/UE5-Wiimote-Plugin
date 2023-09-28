#include "WiimotePlugin.h"
#include "WiimotePrivatePCH.h"

IMPLEMENT_MODULE(FWiimotePlugin, Wiimote)

TSharedPtr<class IInputDevice> FWiimotePlugin::CreateInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler)
{
	WiimoteDevice = MakeShareable(new FWiimoteInputDevice(InMessageHandler));
	return WiimoteDevice;
}

void FWiimotePlugin::ShutdownModule()
{
	if (WiimoteDevice.IsValid())
	{
		WiimoteDevice = nullptr;
	}
}
