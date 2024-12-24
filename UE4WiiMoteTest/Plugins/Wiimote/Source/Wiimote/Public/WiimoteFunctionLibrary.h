// Copyright 2015 Tencent Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h" // needed for access to UBlueprintFunctionLibrary
#include "WiimoteFunctionLibrary.generated.h"

struct WIIMOTE_API FWiimoteKeyNames
{
	static const FGamepadKeyNames::Type Wiimote_DPad_Up;
	static const FGamepadKeyNames::Type Wiimote_DPad_Down;
	static const FGamepadKeyNames::Type Wiimote_DPad_Right;
	static const FGamepadKeyNames::Type Wiimote_DPad_Left;
	static const FGamepadKeyNames::Type Wiimote_Plus;
	static const FGamepadKeyNames::Type Wiimote_Home;
	static const FGamepadKeyNames::Type Wiimote_Minus;
	static const FGamepadKeyNames::Type Wiimote_Button_A;
	static const FGamepadKeyNames::Type Wiimote_Button_B;
	static const FGamepadKeyNames::Type Wiimote_Button_1;
	static const FGamepadKeyNames::Type Wiimote_Button_2;
	static const FGamepadKeyNames::Type Wiimote_PointerVisible;
	static const FGamepadKeyNames::Type Wiimote_PointerDistance;
	static const FGamepadKeyNames::Type Wiimote_PointerAngle;
	static const FGamepadKeyNames::Type Wiimote_PointerX;
	static const FGamepadKeyNames::Type Wiimote_PointerY;
	static const FGamepadKeyNames::Type Wiimote_Pointer2D;
	static const FGamepadKeyNames::Type Wiimote_BatteryLevel;
	static const FGamepadKeyNames::Type Nunchuck_Button_C;
	static const FGamepadKeyNames::Type Nunchuck_Button_Z;
	static const FGamepadKeyNames::Type Nunchuck_StickX;
	static const FGamepadKeyNames::Type Nunchuck_StickY;
	static const FGamepadKeyNames::Type Nunchuck_Stick2D;

};

struct WIIMOTE_API FWiimoteKeys
{
	static const FKey Wiimote_DPad_Up;
	static const FKey Wiimote_DPad_Down;
	static const FKey Wiimote_DPad_Right;
	static const FKey Wiimote_DPad_Left;
	static const FKey Wiimote_Plus;
	static const FKey Wiimote_Home;
	static const FKey Wiimote_Minus;
	static const FKey Wiimote_Button_A;
	static const FKey Wiimote_Button_B;
	static const FKey Wiimote_Button_1;
	static const FKey Wiimote_Button_2;
	static const FKey Wiimote_PointerVisible;
	static const FKey Wiimote_PointerDistance;
	static const FKey Wiimote_PointerAngle;
	static const FKey Wiimote_PointerX;
	static const FKey Wiimote_PointerY;
	static const FKey Wiimote_Pointer2D;
	static const FKey Wiimote_BatteryLevel;
	static const FKey Nunchuck_Button_C;
	static const FKey Nunchuck_Button_Z;
	static const FKey Nunchuck_StickX;
	static const FKey Nunchuck_StickY;
	static const FKey Nunchuck_Stick2D;
};

UCLASS()
class WIIMOTE_API UWiimoteFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Wiimote")
	static void SetIREnabled(int32 ControllerId, bool IsEnabled);

	UFUNCTION(BlueprintCallable, Category = "Wiimote")
	static void GetIRDots(int32 ControllerId, TArray<FVector2D>& OutResult_);

	UFUNCTION(BlueprintCallable, Category = "Wiimote")
	static void GetIRResolution(int32 ControllerId, FVector2D& OutResult_);
	
	UFUNCTION(BlueprintCallable, Category = "Wiimote")
	static void SetMotionPlusEnabled(int32 ControllerId, bool IsEnabled);
	
	UFUNCTION(BlueprintCallable, Category= "Wiimote")
	static void SetMotionSensingEnabled(int32 ControllerId, bool IsEnabled);

	UFUNCTION(BlueprintCallable, Category = "Wiimote")
	static void SetRumbleEnabled(int32 ControllerId, bool IsEnabled);

	UFUNCTION(BlueprintCallable, Category = "Wiimote")
	static void ScanWiimotes();
};