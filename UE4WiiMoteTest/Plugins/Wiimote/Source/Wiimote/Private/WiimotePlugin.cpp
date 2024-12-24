
#include "WiimotePlugin.h"
#include "WiimotePrivatePCH.h"
#include "../Public/WiimoteFunctionLibrary.h"
#include <InputCoreTypes.h>
#include <WiimoteInputDevice.h>
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "Wiimote"

IMPLEMENT_MODULE(FWiimotePlugin, Wiimote)

TSharedPtr<class IInputDevice> FWiimotePlugin::CreateInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler)
{
	WiimoteDevice = MakeShareable(new FWiimoteInputDevice(InMessageHandler));
	return WiimoteDevice;
}


void FWiimotePlugin::StartupModule()
{
    FString BaseDir = IPluginManager::Get().FindPlugin("Wiimote")->GetBaseDir();


    // Add on the relative location of the third party dll and load it
    FString LibraryPath;
    LibraryPath = FPaths::Combine(
        *BaseDir,
        TEXT("Thirdparty/WiiUse/lib/Win64/wiiuse.dll"));

    // Getting the handle to the DLL methods
    WiimoteHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;
    if (WiimoteHandle)
    {
        // Do something when the DLL is first loaded
    }
    else
    {
        FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "Failed to load WiiUse third party library"));
    }

	IInputDeviceModule::StartupModule();

	const FName NAME_Wiimote(TEXT("Wiimote"));

	EKeys::AddMenuCategoryDisplayInfo(NAME_Wiimote, LOCTEXT("WiimoteSubCategory", "Wiimote"), TEXT("GraphEditor.PadEvent_16x"));


	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Nunchuck_StickX, LOCTEXT("Nunchuck_StickX", "Nunchuck Control Stick X-Axis"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D, NAME_Wiimote));
	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Nunchuck_StickY, LOCTEXT("Nunchuck_StickY", "Nunchuck Control Stick Y-Axis"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D, NAME_Wiimote));
	EKeys::AddPairedKey(FKeyDetails(FWiimoteKeyNames::Nunchuck_Stick2D, LOCTEXT("Nunchuck_Stick2D", "Nunchuck Control Stick 2D-Axis"), FKeyDetails::GamepadKey | FKeyDetails::Axis2D, NAME_Wiimote),
		FWiimoteKeyNames::Nunchuck_StickX, FWiimoteKeyNames::Nunchuck_StickY);
	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Wiimote_PointerVisible, LOCTEXT("Wiimote_PointerVisible", "Wiimote Pointer Visible"), FKeyDetails::GamepadKey, NAME_Wiimote));
	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Wiimote_PointerDistance, LOCTEXT("Wiimote_PointerDistance", "Wiimote Pointer Distance"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D, NAME_Wiimote));
	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Wiimote_PointerAngle, LOCTEXT("Wiimote_PointerAngle", "Wiimote Pointer Angle"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D, NAME_Wiimote));
	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Wiimote_PointerX, LOCTEXT("Wiimote_PointerX", "Wiimote Pointer X-Axis"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D, NAME_Wiimote));
	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Wiimote_PointerY, LOCTEXT("Wiimote_PointerY", "Wiimote Pointer Y-Axis"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D, NAME_Wiimote));
	EKeys::AddPairedKey(FKeyDetails(FWiimoteKeyNames::Wiimote_Pointer2D, LOCTEXT("Wiimote_Pointer2D", "Wiimote Pointer 2D-Axis"), FKeyDetails::GamepadKey | FKeyDetails::Axis2D, NAME_Wiimote),
		FWiimoteKeyNames::Wiimote_PointerX, FWiimoteKeyNames::Wiimote_PointerY);
	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Wiimote_BatteryLevel, LOCTEXT("Wiimote_BatteryLevel", "Wiimote Battery Level"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D, NAME_Wiimote));
	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Wiimote_DPad_Up, LOCTEXT("Wiimote_DPad_Up", "Wiimote DPad Up"), FKeyDetails::GamepadKey, NAME_Wiimote));
	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Wiimote_DPad_Down, LOCTEXT("Wiimote_DPad_Down", "Wiimote DPad Down"), FKeyDetails::GamepadKey, NAME_Wiimote));
	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Wiimote_DPad_Right, LOCTEXT("Wiimote_DPad_Right", "Wiimote DPad Right"), FKeyDetails::GamepadKey, NAME_Wiimote));
	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Wiimote_DPad_Left, LOCTEXT("Wiimote_DPad_Left", "Wiimote DPad Left"), FKeyDetails::GamepadKey, NAME_Wiimote));
	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Wiimote_Plus, LOCTEXT("Wiimote_Plus", "Wiimote Plus"), FKeyDetails::GamepadKey, NAME_Wiimote));
	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Wiimote_Home, LOCTEXT("Wiimote_Home", "Wiimote Home"), FKeyDetails::GamepadKey, NAME_Wiimote));
	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Wiimote_Minus, LOCTEXT("Wiimote_Minus", "Wiimote Minus"), FKeyDetails::GamepadKey, NAME_Wiimote));
	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Wiimote_Button_A, LOCTEXT("Wiimote_Button_A", "Wiimote Button A"), FKeyDetails::GamepadKey, NAME_Wiimote));
	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Wiimote_Button_B, LOCTEXT("Wiimote_Button_B", "Wiimote Button B"), FKeyDetails::GamepadKey, NAME_Wiimote));
	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Wiimote_Button_1, LOCTEXT("Wiimote_Button_1", "Wiimote Button 1"), FKeyDetails::GamepadKey, NAME_Wiimote));
	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Wiimote_Button_2, LOCTEXT("Wiimote_Button_2", "Wiimote Button 2"), FKeyDetails::GamepadKey, NAME_Wiimote));
	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Nunchuck_Button_C, LOCTEXT("Nunchuck_Button_C", "Nunchuck Button C"), FKeyDetails::GamepadKey, NAME_Wiimote));
	EKeys::AddKey(FKeyDetails(FWiimoteKeyNames::Nunchuck_Button_Z, LOCTEXT("Nunchuck_Button_Z", "Nunchuck Button Z"), FKeyDetails::GamepadKey, NAME_Wiimote));

}

void FWiimotePlugin::ShutdownModule()
{
	if (WiimoteDevice.IsValid())
	{
		WiimoteDevice = nullptr;
	}
}
