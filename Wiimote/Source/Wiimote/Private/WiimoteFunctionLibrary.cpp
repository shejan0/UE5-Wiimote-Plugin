#include "WiimoteFunctionLibrary.h"
#include "WiimotePrivatePCH.h"

//#include <WiimoteFunctionLibrary.h>
#include "WiimoteInputDevice.h"
#include <WiimotePlugin.h>


void UWiimoteFunctionLibrary::SetIREnabled(int32 ControllerId, bool IsEnabled)
{
	FWiimoteInputDevice* WiimoteDevice = FWiimotePlugin::GetWiimoteDeviceSafe();
	if (WiimoteDevice)
	{
		WiimoteDevice->SetIREnabled(ControllerId, IsEnabled);
	}
}


void UWiimoteFunctionLibrary::GetIRDots(int32 ControllerId, TArray<FVector2D>& OutResult_)
{
	FWiimoteInputDevice* WiimoteDevice = FWiimotePlugin::GetWiimoteDeviceSafe();
	if (WiimoteDevice)
	{
		WiimoteDevice->GetIRDots(ControllerId, OutResult_);
	}
}


void UWiimoteFunctionLibrary::GetIRResolution(int32 ControllerId, FVector2D& OutResult_)
{
	FWiimoteInputDevice* WiimoteDevice = FWiimotePlugin::GetWiimoteDeviceSafe();
	if (WiimoteDevice)
	{
		WiimoteDevice->GetIRResolution(ControllerId, OutResult_);
	}
}

void UWiimoteFunctionLibrary::SetMotionPlusEnabled(int32 ControllerId, bool IsEnabled)
{
	FWiimoteInputDevice* WiimoteDevice = FWiimotePlugin::GetWiimoteDeviceSafe();
	if (WiimoteDevice)
	{
		WiimoteDevice->SetMotionPlusEnabled(ControllerId, IsEnabled);
	}
}

void UWiimoteFunctionLibrary::SetMotionSensingEnabled(int32 ControllerId, bool IsEnabled)
{
	FWiimoteInputDevice* WiimoteDevice = FWiimotePlugin::GetWiimoteDeviceSafe();
	if (WiimoteDevice)
	{
		WiimoteDevice->SetMotionSensingEnabled(ControllerId, IsEnabled);
	}
}

void UWiimoteFunctionLibrary::SetRumbleEnabled(int32 ControllerId, bool IsEnabled)
{
	FWiimoteInputDevice* WiimoteDevice = FWiimotePlugin::GetWiimoteDeviceSafe();
	if (WiimoteDevice)
	{
		WiimoteDevice->SetRumbleEnabled(ControllerId, IsEnabled);
	}
}

void UWiimoteFunctionLibrary::ScanWiimotes()
{
	FWiimoteInputDevice* WiimoteDevice = FWiimotePlugin::GetWiimoteDeviceSafe();
	if (WiimoteDevice)
	{
		WiimoteDevice->ScanWiimotes();
	}
}
