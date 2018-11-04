// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef WIIMOTE_WiimoteFunctionLibrary_generated_h
#error "WiimoteFunctionLibrary.generated.h already included, missing '#pragma once' in WiimoteFunctionLibrary.h"
#endif
#define WIIMOTE_WiimoteFunctionLibrary_generated_h

#define cppbuilder_Plugins_Wiimote_Source_Wiimote_Public_WiimoteFunctionLibrary_h_11_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetRumbleEnabled) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ControllerId); \
		P_GET_UBOOL(Z_Param_IsEnabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UWiimoteFunctionLibrary::SetRumbleEnabled(Z_Param_ControllerId,Z_Param_IsEnabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMotionSensingEnabled) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ControllerId); \
		P_GET_UBOOL(Z_Param_IsEnabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UWiimoteFunctionLibrary::SetMotionSensingEnabled(Z_Param_ControllerId,Z_Param_IsEnabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMotionPlusEnabled) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ControllerId); \
		P_GET_UBOOL(Z_Param_IsEnabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UWiimoteFunctionLibrary::SetMotionPlusEnabled(Z_Param_ControllerId,Z_Param_IsEnabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetIREnabled) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ControllerId); \
		P_GET_UBOOL(Z_Param_IsEnabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UWiimoteFunctionLibrary::SetIREnabled(Z_Param_ControllerId,Z_Param_IsEnabled); \
		P_NATIVE_END; \
	}


#define cppbuilder_Plugins_Wiimote_Source_Wiimote_Public_WiimoteFunctionLibrary_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetRumbleEnabled) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ControllerId); \
		P_GET_UBOOL(Z_Param_IsEnabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UWiimoteFunctionLibrary::SetRumbleEnabled(Z_Param_ControllerId,Z_Param_IsEnabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMotionSensingEnabled) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ControllerId); \
		P_GET_UBOOL(Z_Param_IsEnabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UWiimoteFunctionLibrary::SetMotionSensingEnabled(Z_Param_ControllerId,Z_Param_IsEnabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMotionPlusEnabled) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ControllerId); \
		P_GET_UBOOL(Z_Param_IsEnabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UWiimoteFunctionLibrary::SetMotionPlusEnabled(Z_Param_ControllerId,Z_Param_IsEnabled); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetIREnabled) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ControllerId); \
		P_GET_UBOOL(Z_Param_IsEnabled); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UWiimoteFunctionLibrary::SetIREnabled(Z_Param_ControllerId,Z_Param_IsEnabled); \
		P_NATIVE_END; \
	}


#define cppbuilder_Plugins_Wiimote_Source_Wiimote_Public_WiimoteFunctionLibrary_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUWiimoteFunctionLibrary(); \
	friend struct Z_Construct_UClass_UWiimoteFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UWiimoteFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Wiimote"), NO_API) \
	DECLARE_SERIALIZER(UWiimoteFunctionLibrary)


#define cppbuilder_Plugins_Wiimote_Source_Wiimote_Public_WiimoteFunctionLibrary_h_11_INCLASS \
private: \
	static void StaticRegisterNativesUWiimoteFunctionLibrary(); \
	friend struct Z_Construct_UClass_UWiimoteFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UWiimoteFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Wiimote"), NO_API) \
	DECLARE_SERIALIZER(UWiimoteFunctionLibrary)


#define cppbuilder_Plugins_Wiimote_Source_Wiimote_Public_WiimoteFunctionLibrary_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWiimoteFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWiimoteFunctionLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWiimoteFunctionLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWiimoteFunctionLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWiimoteFunctionLibrary(UWiimoteFunctionLibrary&&); \
	NO_API UWiimoteFunctionLibrary(const UWiimoteFunctionLibrary&); \
public:


#define cppbuilder_Plugins_Wiimote_Source_Wiimote_Public_WiimoteFunctionLibrary_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWiimoteFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWiimoteFunctionLibrary(UWiimoteFunctionLibrary&&); \
	NO_API UWiimoteFunctionLibrary(const UWiimoteFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWiimoteFunctionLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWiimoteFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWiimoteFunctionLibrary)


#define cppbuilder_Plugins_Wiimote_Source_Wiimote_Public_WiimoteFunctionLibrary_h_11_PRIVATE_PROPERTY_OFFSET
#define cppbuilder_Plugins_Wiimote_Source_Wiimote_Public_WiimoteFunctionLibrary_h_8_PROLOG
#define cppbuilder_Plugins_Wiimote_Source_Wiimote_Public_WiimoteFunctionLibrary_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	cppbuilder_Plugins_Wiimote_Source_Wiimote_Public_WiimoteFunctionLibrary_h_11_PRIVATE_PROPERTY_OFFSET \
	cppbuilder_Plugins_Wiimote_Source_Wiimote_Public_WiimoteFunctionLibrary_h_11_RPC_WRAPPERS \
	cppbuilder_Plugins_Wiimote_Source_Wiimote_Public_WiimoteFunctionLibrary_h_11_INCLASS \
	cppbuilder_Plugins_Wiimote_Source_Wiimote_Public_WiimoteFunctionLibrary_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define cppbuilder_Plugins_Wiimote_Source_Wiimote_Public_WiimoteFunctionLibrary_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	cppbuilder_Plugins_Wiimote_Source_Wiimote_Public_WiimoteFunctionLibrary_h_11_PRIVATE_PROPERTY_OFFSET \
	cppbuilder_Plugins_Wiimote_Source_Wiimote_Public_WiimoteFunctionLibrary_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	cppbuilder_Plugins_Wiimote_Source_Wiimote_Public_WiimoteFunctionLibrary_h_11_INCLASS_NO_PURE_DECLS \
	cppbuilder_Plugins_Wiimote_Source_Wiimote_Public_WiimoteFunctionLibrary_h_11_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class WiimoteFunctionLibrary."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID cppbuilder_Plugins_Wiimote_Source_Wiimote_Public_WiimoteFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
