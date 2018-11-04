// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Wiimote/Private/WiimotePrivatePCH.h"
#include "Wiimote/Public/WiimoteFunctionLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWiimoteFunctionLibrary() {}
// Cross Module References
	WIIMOTE_API UClass* Z_Construct_UClass_UWiimoteFunctionLibrary_NoRegister();
	WIIMOTE_API UClass* Z_Construct_UClass_UWiimoteFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_Wiimote();
	WIIMOTE_API UFunction* Z_Construct_UFunction_UWiimoteFunctionLibrary_SetIREnabled();
	WIIMOTE_API UFunction* Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionPlusEnabled();
	WIIMOTE_API UFunction* Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionSensingEnabled();
	WIIMOTE_API UFunction* Z_Construct_UFunction_UWiimoteFunctionLibrary_SetRumbleEnabled();
// End Cross Module References
	void UWiimoteFunctionLibrary::StaticRegisterNativesUWiimoteFunctionLibrary()
	{
		UClass* Class = UWiimoteFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetIREnabled", &UWiimoteFunctionLibrary::execSetIREnabled },
			{ "SetMotionPlusEnabled", &UWiimoteFunctionLibrary::execSetMotionPlusEnabled },
			{ "SetMotionSensingEnabled", &UWiimoteFunctionLibrary::execSetMotionSensingEnabled },
			{ "SetRumbleEnabled", &UWiimoteFunctionLibrary::execSetRumbleEnabled },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UWiimoteFunctionLibrary_SetIREnabled_Statics
	{
		struct WiimoteFunctionLibrary_eventSetIREnabled_Parms
		{
			int32 ControllerId;
			bool IsEnabled;
		};
		static void NewProp_IsEnabled_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsEnabled;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ControllerId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UWiimoteFunctionLibrary_SetIREnabled_Statics::NewProp_IsEnabled_SetBit(void* Obj)
	{
		((WiimoteFunctionLibrary_eventSetIREnabled_Parms*)Obj)->IsEnabled = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWiimoteFunctionLibrary_SetIREnabled_Statics::NewProp_IsEnabled = { UE4CodeGen_Private::EPropertyClass::Bool, "IsEnabled", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(WiimoteFunctionLibrary_eventSetIREnabled_Parms), &Z_Construct_UFunction_UWiimoteFunctionLibrary_SetIREnabled_Statics::NewProp_IsEnabled_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UWiimoteFunctionLibrary_SetIREnabled_Statics::NewProp_ControllerId = { UE4CodeGen_Private::EPropertyClass::Int, "ControllerId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WiimoteFunctionLibrary_eventSetIREnabled_Parms, ControllerId), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWiimoteFunctionLibrary_SetIREnabled_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWiimoteFunctionLibrary_SetIREnabled_Statics::NewProp_IsEnabled,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWiimoteFunctionLibrary_SetIREnabled_Statics::NewProp_ControllerId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWiimoteFunctionLibrary_SetIREnabled_Statics::Function_MetaDataParams[] = {
		{ "Category", "Wiimote" },
		{ "ModuleRelativePath", "Public/WiimoteFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UWiimoteFunctionLibrary_SetIREnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWiimoteFunctionLibrary, "SetIREnabled", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(WiimoteFunctionLibrary_eventSetIREnabled_Parms), Z_Construct_UFunction_UWiimoteFunctionLibrary_SetIREnabled_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UWiimoteFunctionLibrary_SetIREnabled_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWiimoteFunctionLibrary_SetIREnabled_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UWiimoteFunctionLibrary_SetIREnabled_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWiimoteFunctionLibrary_SetIREnabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UWiimoteFunctionLibrary_SetIREnabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionPlusEnabled_Statics
	{
		struct WiimoteFunctionLibrary_eventSetMotionPlusEnabled_Parms
		{
			int32 ControllerId;
			bool IsEnabled;
		};
		static void NewProp_IsEnabled_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsEnabled;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ControllerId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionPlusEnabled_Statics::NewProp_IsEnabled_SetBit(void* Obj)
	{
		((WiimoteFunctionLibrary_eventSetMotionPlusEnabled_Parms*)Obj)->IsEnabled = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionPlusEnabled_Statics::NewProp_IsEnabled = { UE4CodeGen_Private::EPropertyClass::Bool, "IsEnabled", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(WiimoteFunctionLibrary_eventSetMotionPlusEnabled_Parms), &Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionPlusEnabled_Statics::NewProp_IsEnabled_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionPlusEnabled_Statics::NewProp_ControllerId = { UE4CodeGen_Private::EPropertyClass::Int, "ControllerId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WiimoteFunctionLibrary_eventSetMotionPlusEnabled_Parms, ControllerId), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionPlusEnabled_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionPlusEnabled_Statics::NewProp_IsEnabled,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionPlusEnabled_Statics::NewProp_ControllerId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionPlusEnabled_Statics::Function_MetaDataParams[] = {
		{ "Category", "Wiimote" },
		{ "ModuleRelativePath", "Public/WiimoteFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionPlusEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWiimoteFunctionLibrary, "SetMotionPlusEnabled", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(WiimoteFunctionLibrary_eventSetMotionPlusEnabled_Parms), Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionPlusEnabled_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionPlusEnabled_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionPlusEnabled_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionPlusEnabled_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionPlusEnabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionPlusEnabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionSensingEnabled_Statics
	{
		struct WiimoteFunctionLibrary_eventSetMotionSensingEnabled_Parms
		{
			int32 ControllerId;
			bool IsEnabled;
		};
		static void NewProp_IsEnabled_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsEnabled;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ControllerId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionSensingEnabled_Statics::NewProp_IsEnabled_SetBit(void* Obj)
	{
		((WiimoteFunctionLibrary_eventSetMotionSensingEnabled_Parms*)Obj)->IsEnabled = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionSensingEnabled_Statics::NewProp_IsEnabled = { UE4CodeGen_Private::EPropertyClass::Bool, "IsEnabled", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(WiimoteFunctionLibrary_eventSetMotionSensingEnabled_Parms), &Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionSensingEnabled_Statics::NewProp_IsEnabled_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionSensingEnabled_Statics::NewProp_ControllerId = { UE4CodeGen_Private::EPropertyClass::Int, "ControllerId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WiimoteFunctionLibrary_eventSetMotionSensingEnabled_Parms, ControllerId), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionSensingEnabled_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionSensingEnabled_Statics::NewProp_IsEnabled,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionSensingEnabled_Statics::NewProp_ControllerId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionSensingEnabled_Statics::Function_MetaDataParams[] = {
		{ "Category", "Wiimote" },
		{ "ModuleRelativePath", "Public/WiimoteFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionSensingEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWiimoteFunctionLibrary, "SetMotionSensingEnabled", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(WiimoteFunctionLibrary_eventSetMotionSensingEnabled_Parms), Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionSensingEnabled_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionSensingEnabled_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionSensingEnabled_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionSensingEnabled_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionSensingEnabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionSensingEnabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UWiimoteFunctionLibrary_SetRumbleEnabled_Statics
	{
		struct WiimoteFunctionLibrary_eventSetRumbleEnabled_Parms
		{
			int32 ControllerId;
			bool IsEnabled;
		};
		static void NewProp_IsEnabled_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsEnabled;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ControllerId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UWiimoteFunctionLibrary_SetRumbleEnabled_Statics::NewProp_IsEnabled_SetBit(void* Obj)
	{
		((WiimoteFunctionLibrary_eventSetRumbleEnabled_Parms*)Obj)->IsEnabled = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWiimoteFunctionLibrary_SetRumbleEnabled_Statics::NewProp_IsEnabled = { UE4CodeGen_Private::EPropertyClass::Bool, "IsEnabled", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(WiimoteFunctionLibrary_eventSetRumbleEnabled_Parms), &Z_Construct_UFunction_UWiimoteFunctionLibrary_SetRumbleEnabled_Statics::NewProp_IsEnabled_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UWiimoteFunctionLibrary_SetRumbleEnabled_Statics::NewProp_ControllerId = { UE4CodeGen_Private::EPropertyClass::Int, "ControllerId", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WiimoteFunctionLibrary_eventSetRumbleEnabled_Parms, ControllerId), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWiimoteFunctionLibrary_SetRumbleEnabled_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWiimoteFunctionLibrary_SetRumbleEnabled_Statics::NewProp_IsEnabled,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWiimoteFunctionLibrary_SetRumbleEnabled_Statics::NewProp_ControllerId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWiimoteFunctionLibrary_SetRumbleEnabled_Statics::Function_MetaDataParams[] = {
		{ "Category", "Wiimote" },
		{ "ModuleRelativePath", "Public/WiimoteFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UWiimoteFunctionLibrary_SetRumbleEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWiimoteFunctionLibrary, "SetRumbleEnabled", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(WiimoteFunctionLibrary_eventSetRumbleEnabled_Parms), Z_Construct_UFunction_UWiimoteFunctionLibrary_SetRumbleEnabled_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UWiimoteFunctionLibrary_SetRumbleEnabled_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWiimoteFunctionLibrary_SetRumbleEnabled_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UWiimoteFunctionLibrary_SetRumbleEnabled_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWiimoteFunctionLibrary_SetRumbleEnabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UWiimoteFunctionLibrary_SetRumbleEnabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UWiimoteFunctionLibrary_NoRegister()
	{
		return UWiimoteFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UWiimoteFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UWiimoteFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_Wiimote,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UWiimoteFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UWiimoteFunctionLibrary_SetIREnabled, "SetIREnabled" }, // 3727488841
		{ &Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionPlusEnabled, "SetMotionPlusEnabled" }, // 2141241023
		{ &Z_Construct_UFunction_UWiimoteFunctionLibrary_SetMotionSensingEnabled, "SetMotionSensingEnabled" }, // 2090667946
		{ &Z_Construct_UFunction_UWiimoteFunctionLibrary_SetRumbleEnabled, "SetRumbleEnabled" }, // 973891810
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UWiimoteFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "WiimoteFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/WiimoteFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UWiimoteFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWiimoteFunctionLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UWiimoteFunctionLibrary_Statics::ClassParams = {
		&UWiimoteFunctionLibrary::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UWiimoteFunctionLibrary_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UWiimoteFunctionLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UWiimoteFunctionLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UWiimoteFunctionLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UWiimoteFunctionLibrary, 39568754);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UWiimoteFunctionLibrary(Z_Construct_UClass_UWiimoteFunctionLibrary, &UWiimoteFunctionLibrary::StaticClass, TEXT("/Script/Wiimote"), TEXT("UWiimoteFunctionLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UWiimoteFunctionLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
