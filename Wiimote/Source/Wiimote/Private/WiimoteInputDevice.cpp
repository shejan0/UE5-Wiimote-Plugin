// Copyright 2015 Tencent Games, Inc. All Rights Reserved.
#include "WiimoteInputDevice.h"
#include "WiimotePrivatePCH.h"
#include <WiimoteFunctionLibrary.h>
#include <Kismet/KismetMathLibrary.h>


const FGamepadKeyNames::Type FWiimoteKeyNames::Wiimote_DPad_Up("Wiimote_DPad_Up");
const FGamepadKeyNames::Type FWiimoteKeyNames::Wiimote_DPad_Down("Wiimote_DPad_Down");
const FGamepadKeyNames::Type FWiimoteKeyNames::Wiimote_DPad_Right("Wiimote_DPad_Right");
const FGamepadKeyNames::Type FWiimoteKeyNames::Wiimote_DPad_Left("Wiimote_DPad_Left");
const FGamepadKeyNames::Type FWiimoteKeyNames::Wiimote_Plus("Wiimote_Plus");
const FGamepadKeyNames::Type FWiimoteKeyNames::Wiimote_Home("Wiimote_Home");
const FGamepadKeyNames::Type FWiimoteKeyNames::Wiimote_Minus("Wiimote_Minus");
const FGamepadKeyNames::Type FWiimoteKeyNames::Wiimote_Button_A("Wiimote_Button_A");
const FGamepadKeyNames::Type FWiimoteKeyNames::Wiimote_Button_B("Wiimote_Button_B");
const FGamepadKeyNames::Type FWiimoteKeyNames::Wiimote_Button_1("Wiimote_Button_1");
const FGamepadKeyNames::Type FWiimoteKeyNames::Wiimote_Button_2("Wiimote_Button_2");
const FGamepadKeyNames::Type FWiimoteKeyNames::Wiimote_PointerVisible("Wiimote_PointerVisible");
const FGamepadKeyNames::Type FWiimoteKeyNames::Wiimote_PointerDistance("Wiimote_PointerDistance");
const FGamepadKeyNames::Type FWiimoteKeyNames::Wiimote_PointerAngle("Wiimote_PointerAngle");
const FGamepadKeyNames::Type FWiimoteKeyNames::Wiimote_PointerX("Wiimote_PointerX");
const FGamepadKeyNames::Type FWiimoteKeyNames::Wiimote_PointerY("Wiimote_PointerY");
const FGamepadKeyNames::Type FWiimoteKeyNames::Wiimote_Pointer2D("Wiimote_Pointer2D");
const FGamepadKeyNames::Type FWiimoteKeyNames::Wiimote_BatteryLevel("Wiimote_BatteryLevel");
const FGamepadKeyNames::Type FWiimoteKeyNames::Nunchuck_Button_C("Nunchuck_Button_C");
const FGamepadKeyNames::Type FWiimoteKeyNames::Nunchuck_Button_Z("Nunchuck_Button_Z");
const FGamepadKeyNames::Type FWiimoteKeyNames::Nunchuck_StickX("Nunchuck_StickX");
const FGamepadKeyNames::Type FWiimoteKeyNames::Nunchuck_StickY("Nunchuck_StickY");
const FGamepadKeyNames::Type FWiimoteKeyNames::Nunchuck_Stick2D("Nunchuck_Stick2D");

const FKey FWiimoteKeys::Wiimote_DPad_Up(FWiimoteKeyNames::Wiimote_DPad_Up);
const FKey FWiimoteKeys::Wiimote_DPad_Down(FWiimoteKeyNames::Wiimote_DPad_Down);
const FKey FWiimoteKeys::Wiimote_DPad_Right(FWiimoteKeyNames::Wiimote_DPad_Right);
const FKey FWiimoteKeys::Wiimote_DPad_Left(FWiimoteKeyNames::Wiimote_DPad_Left);
const FKey FWiimoteKeys::Wiimote_Plus(FWiimoteKeyNames::Wiimote_Plus);
const FKey FWiimoteKeys::Wiimote_Home(FWiimoteKeyNames::Wiimote_Home);
const FKey FWiimoteKeys::Wiimote_Minus(FWiimoteKeyNames::Wiimote_Minus);
const FKey FWiimoteKeys::Wiimote_Button_A(FWiimoteKeyNames::Wiimote_Button_A);
const FKey FWiimoteKeys::Wiimote_Button_B(FWiimoteKeyNames::Wiimote_Button_B);
const FKey FWiimoteKeys::Wiimote_Button_1(FWiimoteKeyNames::Wiimote_Button_1);
const FKey FWiimoteKeys::Wiimote_Button_2(FWiimoteKeyNames::Wiimote_Button_2);
const FKey FWiimoteKeys::Wiimote_PointerVisible(FWiimoteKeyNames::Wiimote_PointerVisible);
const FKey FWiimoteKeys::Wiimote_PointerDistance(FWiimoteKeyNames::Wiimote_PointerDistance);
const FKey FWiimoteKeys::Wiimote_PointerAngle(FWiimoteKeyNames::Wiimote_PointerAngle);
const FKey FWiimoteKeys::Wiimote_PointerX(FWiimoteKeyNames::Wiimote_PointerX);
const FKey FWiimoteKeys::Wiimote_PointerY(FWiimoteKeyNames::Wiimote_PointerY);
const FKey FWiimoteKeys::Wiimote_Pointer2D(FWiimoteKeyNames::Wiimote_Pointer2D);
const FKey FWiimoteKeys::Wiimote_BatteryLevel(FWiimoteKeyNames::Wiimote_BatteryLevel);
const FKey FWiimoteKeys::Nunchuck_Button_C(FWiimoteKeyNames::Nunchuck_Button_C);
const FKey FWiimoteKeys::Nunchuck_Button_Z(FWiimoteKeyNames::Nunchuck_Button_Z);
const FKey FWiimoteKeys::Nunchuck_StickX(FWiimoteKeyNames::Nunchuck_StickX);
const FKey FWiimoteKeys::Nunchuck_StickY(FWiimoteKeyNames::Nunchuck_StickY);
const FKey FWiimoteKeys::Nunchuck_Stick2D(FWiimoteKeyNames::Nunchuck_Stick2D);

FWiimoteInputDevice::FWiimoteInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler)
    : MessageHandler(InMessageHandler)
{
    InitialButtonRepeatDelay = 0.2f;
    ButtonRepeatDelay = 0.1f;
    LastForceFeedbackValues.AddUninitialized(MAX_WIIMOTES);

    Buttons[0] =  FWiimoteKeyNames::Wiimote_Button_A;        //WIIMOTE_BUTTON_A
    Buttons[1] =  FWiimoteKeyNames::Wiimote_Button_B;        //WIIMOTE_BUTTON_B
    Buttons[2] =  FWiimoteKeyNames::Wiimote_Button_1;        //WIIMOTE_BUTTON_ONE
    Buttons[3] =  FWiimoteKeyNames::Wiimote_Button_2;        //WIIMOTE_BUTTON_TWO
    Buttons[4] =  FWiimoteKeyNames::Wiimote_Plus;            //WIIMOTE_BUTTON_PLUS
    Buttons[5] =  FWiimoteKeyNames::Wiimote_Minus;           //WIIMOTE_BUTTON_MINUS
    Buttons[6] =  FWiimoteKeyNames::Wiimote_DPad_Up;         //WIIMOTE_BUTTON_UP
    Buttons[7] =  FWiimoteKeyNames::Wiimote_DPad_Down;       //WIIMOTE_BUTTON_DOWN
    Buttons[8] =  FWiimoteKeyNames::Wiimote_DPad_Left;       //WIIMOTE_BUTTON_LEFT
    Buttons[9] =  FWiimoteKeyNames::Wiimote_DPad_Right;      //WIIMOTE_BUTTON_RIGHT
	Buttons[10] = FWiimoteKeyNames::Wiimote_Home;            //WIIMOTE_BUTTON_HOME
	Buttons[11] = FWiimoteKeyNames::Nunchuck_Button_C;       //NUNCHUK_BUTTON_C
    Buttons[12] = FWiimoteKeyNames::Nunchuck_Button_Z;       //NUNCHUK_BUTTON_Z
    Buttons[13] = FWiimoteKeyNames::Wiimote_PointerVisible;

	GWiimotes = wiiuse_init(MAX_WIIMOTES);
    ScanWiimotes();
}

FWiimoteInputDevice::~FWiimoteInputDevice()
{
    /*
    *   Disconnect the wiimotes
    */
    wiiuse_cleanup(GWiimotes, MAX_WIIMOTES);
}

void FWiimoteInputDevice::Tick(float DeltaTime)
{

}

void FWiimoteInputDevice::SendControllerEvents()
{
    /*
    *   Maybe I'm interested in the battery power of the 0th
    *   wiimote.  This should be WIIMOTE_ID_1 but to be sure
    *   you can get the wiimote associated with WIIMOTE_ID_1
    *   using the wiiuse_get_by_id() function.
    *
    *   A status request will return other things too, like
    *   if any expansions are plugged into the wiimote or
    *   what LEDs are lit.
    */
    /* wiiuse_status(wiimotes[0]); */

    /*
    *   This is the main loop
    *
    *   wiiuse_poll() needs to be called with the wiimote array
    *   and the number of wiimote structures in that array
    *   (it doesn't matter if some of those wiimotes are not used
    *   or are not connected).
    *
    *   This function will set the event flag for each wiimote
    *   when the wiimote has things to report.
    */

    if (AnyWiimoteConnected())
		{
			if (!wiiuse_poll(GWiimotes, MAX_WIIMOTES)) return;
      /*
      *   This happens if something happened on any wiimote.
      *   So go through each one and check if anything happened.
      */
      const double CurrentTime = FPlatformTime::Seconds();
      for (int i = 0; i < MAX_WIIMOTES; ++i)
      {
          FControllerState& ControllerState = ControllerStates[i];
          ControllerState.Wiimote = GWiimotes[i];
          if (ControllerState.Wiimote && WIIMOTE_IS_CONNECTED(ControllerState.Wiimote))
          {
              // Check Analog state
              if (ControllerState.Wiimote->exp.type == EXP_NUNCHUK ||
                  ControllerState.Wiimote->exp.type == EXP_MOTION_PLUS_NUNCHUK)
              {
                  /* nunchuk */
                  struct nunchuk_t* nc = (nunchuk_t*)&ControllerState.Wiimote->exp.nunchuk;

									MessageHandler->OnControllerAnalog(FWiimoteKeyNames::Nunchuck_StickX, ControllerState.ControllerId, nc->js.x);
									MessageHandler->OnControllerAnalog(FWiimoteKeyNames::Nunchuck_StickY, ControllerState.ControllerId, nc->js.y);
              }
              else
							{
								MessageHandler->OnControllerAnalog(FWiimoteKeyNames::Nunchuck_StickX, ControllerState.ControllerId, 0.f);
								MessageHandler->OnControllerAnalog(FWiimoteKeyNames::Nunchuck_StickY, ControllerState.ControllerId, 0.f);
              }
          }

					FMemory::Memzero(CurrentStates);
					handle_event(ControllerState.Wiimote, i);

          switch (ControllerState.Wiimote->event)
          {
          case WIIUSE_STATUS:
              /* a status event occurred */
              handle_ctrl_status(ControllerState.Wiimote, i);
              break;

          case WIIUSE_DISCONNECT:
          case WIIUSE_UNEXPECTED_DISCONNECT:
              /* the wiimote disconnected */
              handle_disconnect(ControllerState.Wiimote, i);
              break;

          case WIIUSE_READ_DATA:
              /*
              *   Data we requested to read was returned.
              *   Take a look at ControllerState.Wiimote>read_req
              *   for the data.
              */
              break;

          case WIIUSE_NUNCHUK_INSERTED:
              /*
              *   a nunchuk was inserted
              *   This is a good place to set any nunchuk specific
              *   threshold values.  By default they are the same
              *   as the wiimote.
              */
              /* wiiuse_set_nunchuk_orient_threshold((struct nunchuk_t*)&wiimotes[i]->exp.nunchuk, 90.0f); */
              /* wiiuse_set_nunchuk_accel_threshold((struct nunchuk_t*)&wiimotes[i]->exp.nunchuk, 100); */
              UE_LOG(LogWiimote, Log, TEXT("Nunchuk inserted."));
              break;

          case WIIUSE_MOTION_PLUS_ACTIVATED:
              UE_LOG(LogWiimote, Log, TEXT("Motion+ was activated"));
              break;

          case WIIUSE_NUNCHUK_REMOVED:
          case WIIUSE_MOTION_PLUS_REMOVED:
              /* some expansion was removed */
              handle_ctrl_status(ControllerState.Wiimote, i);
              UE_LOG(LogWiimote, Log, TEXT("An expansion was removed."));
              break;

          default:
              break;
          }
                
          // For each button check against the previous state and send the correct message if any
          for (int32 ButtonIndex = 0; ButtonIndex < MAX_NUM_WIIMOTE_BUTTONS; ++ButtonIndex)
          {
              if (CurrentStates[ButtonIndex] != ControllerState.ButtonStates[ButtonIndex])
              {
                  if (CurrentStates[ButtonIndex])
                  {
                      MessageHandler->OnControllerButtonPressed(Buttons[ButtonIndex], ControllerState.ControllerId, false);
                  }
                  else
                  {
                      MessageHandler->OnControllerButtonReleased(Buttons[ButtonIndex], ControllerState.ControllerId, false);
                  }

                  if (CurrentStates[ButtonIndex] != 0)
                  {
                      // this button was pressed - set the button's NextRepeatTime to the InitialButtonRepeatDelay
                      ControllerState.NextRepeatTime[ButtonIndex] = CurrentTime + InitialButtonRepeatDelay;
                  }
              }
              else if (CurrentStates[ButtonIndex] != 0 && ControllerState.NextRepeatTime[ButtonIndex] <= CurrentTime)
              {
                  MessageHandler->OnControllerButtonPressed(Buttons[ButtonIndex], ControllerState.ControllerId, true);

                  // set the button's NextRepeatTime to the ButtonRepeatDelay
                  ControllerState.NextRepeatTime[ButtonIndex] = CurrentTime + ButtonRepeatDelay;
              }

              // Update the state for next time
              ControllerState.ButtonStates[ButtonIndex] = CurrentStates[ButtonIndex];
          }

      }
        
    }
    
}

void FWiimoteInputDevice::SetMessageHandler(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler)
{
    MessageHandler = InMessageHandler;
}

bool FWiimoteInputDevice::Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar)
{
    return true;
}

void FWiimoteInputDevice::SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value)
{
    bool bShouldRumble = Value > ForceFeedbackThreshold;
    if (bShouldRumble == LastForceFeedbackValues[ControllerId])
    {
        RepeatForceFeedbackTimer += FApp::GetDeltaTime();
        if (RepeatForceFeedbackTimer < RepeatForceFeedbackTime) return;
    }

    RepeatForceFeedbackTimer = 0.f;
    LastForceFeedbackValues[ControllerId] = bShouldRumble;

    SetRumbleEnabled(ControllerId, bShouldRumble);
}

void FWiimoteInputDevice::SetChannelValues(int32 ControllerId, const FForceFeedbackValues& Values)
{
    bool bShouldRumble = FMath::Max3(FMath::Max(Values.LeftLarge, Values.LeftSmall), Values.RightLarge, Values.RightSmall) > ForceFeedbackThreshold;
    if (bShouldRumble == LastForceFeedbackValues[ControllerId])
    {
        RepeatForceFeedbackTimer += FApp::GetDeltaTime();
        if (RepeatForceFeedbackTimer < RepeatForceFeedbackTime) return;
    }

    RepeatForceFeedbackTimer = 0.f;
    LastForceFeedbackValues[ControllerId] = bShouldRumble;

    SetRumbleEnabled(ControllerId, bShouldRumble);
}

void FWiimoteInputDevice::handle_event(struct wiimote_t* wm, int id)
{
   // UE_LOG(LogWiimote, Log, TEXT("\n\n--- EVENT [id %i] ---"), wm->unid);

    CurrentStates[0] = IS_PRESSED(wm, WIIMOTE_BUTTON_A) || IS_HELD(wm, WIIMOTE_BUTTON_A);
    CurrentStates[1] = IS_PRESSED(wm, WIIMOTE_BUTTON_B) || IS_HELD(wm, WIIMOTE_BUTTON_B);
    CurrentStates[2] = IS_PRESSED(wm, WIIMOTE_BUTTON_ONE) || IS_HELD(wm, WIIMOTE_BUTTON_ONE);
    CurrentStates[3] = IS_PRESSED(wm, WIIMOTE_BUTTON_TWO) || IS_HELD(wm, WIIMOTE_BUTTON_TWO);
    CurrentStates[4] = IS_PRESSED(wm, WIIMOTE_BUTTON_PLUS) || IS_HELD(wm, WIIMOTE_BUTTON_PLUS);
    CurrentStates[5] = IS_PRESSED(wm, WIIMOTE_BUTTON_MINUS) || IS_HELD(wm, WIIMOTE_BUTTON_MINUS);
    CurrentStates[6] = IS_PRESSED(wm, WIIMOTE_BUTTON_UP) || IS_HELD(wm, WIIMOTE_BUTTON_UP);
    CurrentStates[7] = IS_PRESSED(wm, WIIMOTE_BUTTON_DOWN) || IS_HELD(wm, WIIMOTE_BUTTON_DOWN);
    CurrentStates[8] = IS_PRESSED(wm, WIIMOTE_BUTTON_LEFT) || IS_HELD(wm, WIIMOTE_BUTTON_LEFT);
    CurrentStates[9] = IS_PRESSED(wm, WIIMOTE_BUTTON_RIGHT) || IS_HELD(wm, WIIMOTE_BUTTON_RIGHT);
    CurrentStates[10] = IS_PRESSED(wm, WIIMOTE_BUTTON_HOME) || IS_HELD(wm, WIIMOTE_BUTTON_HOME);


    /* show events specific to supported expansions */
    if (wm->exp.type == EXP_NUNCHUK || wm->exp.type == EXP_MOTION_PLUS_NUNCHUK)
    {
        /* nunchuk */
        struct nunchuk_t* nc = (nunchuk_t*)&wm->exp.nunchuk;

        const float DEADZONE = 0.6f;

				CurrentStates[11] = IS_PRESSED(nc, NUNCHUK_BUTTON_C) || IS_HELD(wm, NUNCHUK_BUTTON_C);
				CurrentStates[12] = IS_PRESSED(nc, NUNCHUK_BUTTON_Z) || IS_HELD(wm, NUNCHUK_BUTTON_Z);

    }


		// Update motion controls.
		FVector Tilt(0, 0, 0);
		FVector RotationRate(0, 0, 0);
		FVector Gravity(0, 0, 0);
		FVector Acceleration(0, 0, 0);

		/* if the accelerometer is turned on then print angles */
		if (WIIUSE_USING_ACC(wm))
		{
			Tilt.X = -wm->orient.pitch;
			Tilt.Y = wm->orient.yaw;
			Tilt.Z = wm->orient.roll;

			Acceleration.X = wm->accel.x;
			Acceleration.Y = wm->accel.y;
			Acceleration.Z = wm->accel.z;
		}

		if (wm->exp.type == EXP_MOTION_PLUS || wm->exp.type == EXP_MOTION_PLUS_NUNCHUK)
		{
			RotationRate.X = -wm->exp.mp.angle_rate_gyro.pitch;
			RotationRate.Y = wm->exp.mp.angle_rate_gyro.yaw;
			RotationRate.Z = wm->exp.mp.angle_rate_gyro.roll;
		}

		Gravity.X = wm->gforce.x;
		Gravity.Y = wm->gforce.y;
		Gravity.Z = wm->gforce.z;

		MessageHandler->OnMotionDetected(Tilt, RotationRate, Gravity, Acceleration, id);

    /*
    *   If IR tracking is enabled then print the coordinates
    *   on the virtual screen that the wiimote is pointing to.
    *
    *   Also make sure that we see at least 1 dot.
    */
    if (WIIUSE_USING_IR(wm))
		{
      IREvents(wm, id);
		}
		MessageHandler->OnControllerAnalog(FWiimoteKeyNames::Wiimote_BatteryLevel, id, wm->battery_level);
}

void FWiimoteInputDevice::handle_ctrl_status(struct wiimote_t* wm, int id)
{
  /*
    UE_LOG(LogWiimote, Log, TEXT("\n\n--- CONTROLLER STATUS [wiimote id %i] ---"), wm->unid);

    UE_LOG(LogWiimote, Log, TEXT("attachment:      %i"), wm->exp.type);
    UE_LOG(LogWiimote, Log, TEXT("speaker:         %i"), WIIUSE_USING_SPEAKER(wm));
    UE_LOG(LogWiimote, Log, TEXT("ir:              %i"), WIIUSE_USING_IR(wm));
    UE_LOG(LogWiimote, Log, TEXT("leds:            %i %i %i %i"), WIIUSE_IS_LED_SET(wm, 1), WIIUSE_IS_LED_SET(wm, 2), WIIUSE_IS_LED_SET(wm, 3), WIIUSE_IS_LED_SET(wm, 4));
    UE_LOG(LogWiimote, Log, TEXT("battery:         %f %%"), wm->battery_level);
    */
}

void FWiimoteInputDevice::handle_disconnect(struct wiimote_t* wm, int id)
{
    //UE_LOG(LogWiimote, Log, TEXT("\n\n--- DISCONNECTED [wiimote id %i] ---"), wm->unid);
}


void FWiimoteInputDevice::IREvents(struct wiimote_t* wm, int id)
{
	CurrentStates[13] = false;
	bool bBothVisible = true;
	FVector2D	Pos = FVector2D(wm->ir.x, wm->ir.y);;
	/* go through each of the 2 possible IR sources */
	for (int i = 0; i < 2; ++i)
	{
		CurrentStates[13] = CurrentStates[13] || wm->ir.dot[i].visible;
		bBothVisible = bBothVisible && wm->ir.dot[i].visible;
	}

	if (bBothVisible)
	{
		int DirectionX = static_cast<int>(wm->ir.dot[1].rx) - static_cast<int>(wm->ir.dot[0].rx);
		int DirectionY = static_cast<int>(wm->ir.dot[1].ry) - static_cast<int>(wm->ir.dot[0].ry);

		ControllerStates[id].TimeBetweenUpdatesIR += FApp::GetDeltaTime();
		if (ControllerStates[id].TimeBetweenUpdatesIR >= MaxTimeBetweenUpdatesIR)
		{
			ControllerStates[id].TimeBetweenUpdatesIR = 0.f;

			FVector Gravity(wm->gforce.x, wm->gforce.y, wm->gforce.z);
			ControllerStates[id].bIRWrongOrder = CheckGravityIR(Gravity, DirectionX, DirectionY);
		}

		FVector2D Direction = FVector2D(DirectionX, DirectionY);
		Direction = ControllerStates[id].bIRWrongOrder ? -Direction : Direction;

		float Angle = FMath::RadiansToDegrees(acosf(FVector2D::DotProduct(Direction, FVector2D(1, 0)) / (Direction.Size()))) * FMath::Sign(Direction.Y);

		ControllerStates[id].LastAngle = Angle;
		ControllerStates[id].LastIRDistance = wm->ir.distance;
		ControllerStates[id].LastIRDirection = Direction;

	}
	else
	{
		ControllerStates[id].TimeBetweenUpdatesIR = MaxTimeBetweenUpdatesIR;

		float Angle = FMath::RadiansToDegrees(FMath::Atan2(wm->gforce.z, wm->gforce.x)) - 90.f;

		ControllerStates[id].LastAngle = Angle;
	}

	MessageHandler->OnControllerAnalog(FWiimoteKeyNames::Wiimote_PointerDistance, id, ControllerStates[id].LastIRDistance);
	MessageHandler->OnControllerAnalog(FWiimoteKeyNames::Wiimote_PointerAngle, id, ControllerStates[id].LastAngle);

	Pos.X /= wm->ir.vres[0];
	Pos.Y /= wm->ir.vres[1];

	MessageHandler->OnControllerAnalog(FWiimoteKeyNames::Wiimote_PointerX, id, Pos.X);
	MessageHandler->OnControllerAnalog(FWiimoteKeyNames::Wiimote_PointerY, id, Pos.Y);
}

bool FWiimoteInputDevice::CheckGravityIR(const FVector& _Gravity, int _DirectionX, int _DirectionY)
{
	return _Gravity.Z > 0.5f && _DirectionX < 0 ||
		     _Gravity.Z < -0.5f && _DirectionX > 0 ||
         _Gravity.X < -0.5f && _DirectionY < 0 ||
	       _Gravity.X >  0.5f && _DirectionY > 0;
}


bool FWiimoteInputDevice::IsGamepadAttached() const
{
    return AnyWiimoteConnected();
}

bool FWiimoteInputDevice::AnyWiimoteConnected() const
{
    if (!GWiimotes)
    {
        return false;
    }

    for (int i = 0; i < MAX_WIIMOTES; i++)
    {
        if (GWiimotes[i] && WIIMOTE_IS_CONNECTED(GWiimotes[i]))
        {
            return true;
        }
    }

    return false;
}

void FWiimoteInputDevice::SetIREnabled(int32 ControllerId, bool IsEnabled)
{
    if (GWiimotes[ControllerId] == nullptr)
        return;
    if (IsEnabled)
    {
        wiiuse_set_ir(GWiimotes[ControllerId], 1);
        SetAspectRatio(ControllerId,FAspectRatios::IR16_9);
        SetIRPosition(ControllerId, FIRPosition::IRAbove);
        SetIRSensitivity(ControllerId,5);
    }
    else
    {
        wiiuse_set_ir(GWiimotes[ControllerId], 0);
    }
}

void FWiimoteInputDevice::SetAspectRatio(int32 ControllerId, FAspectRatios aspectRatio){
    if (GWiimotes[ControllerId] == nullptr)
        return;
    wiiuse_set_aspect_ratio(GWiimotes[ControllerId], (aspect_t)aspectRatio);
}

void FWiimoteInputDevice::SetIRPosition(int32 ControllerId, FIRPosition irPosition){
    if (GWiimotes[ControllerId] == nullptr)
        return;
    wiiuse_set_ir_position(GWiimotes[ControllerId], (ir_position_t)irPosition);
}

void FWiimoteInputDevice::SetIRSensitivity(int32 ControllerId, int32 sensitivity){
    if (GWiimotes[ControllerId] == nullptr)
        return;
    wiiuse_set_ir_sensitivity(GWiimotes[ControllerId], sensitivity);
}


void FWiimoteInputDevice::GetIRDots(int32 ControllerId, TArray<FVector2D>& OutResult_)
{
  if (!(ControllerId >= 0 || ControllerId < MAX_WIIMOTES)) return;
  
  struct wiimote_t* Wiimote = GWiimotes[ControllerId];
	if (!(Wiimote && WIIMOTE_IS_CONNECTED(Wiimote))) return;

	if (!(WIIUSE_USING_IR(Wiimote))) return;

  for(unsigned int i = 0; i < MAX_IR_DOTS; ++i)
  {
    if (Wiimote->ir.dot[i].visible)
    {
      OutResult_.Add(FVector2D(Wiimote->ir.dot[i].rx, Wiimote->ir.dot[i].ry));
    }
  }
}


void FWiimoteInputDevice::GetIRResolution(int32 ControllerId, FVector2D& OutResult_)
{
	if (!ensureMsgf(ControllerId >= 0 || ControllerId < MAX_WIIMOTES, TEXT("ControllerId out of range"))) return;

	struct wiimote_t* Wiimote = GWiimotes[ControllerId];
	if (!ensureMsgf(Wiimote && WIIMOTE_IS_CONNECTED(Wiimote), TEXT("Controller not connected"))) return;

	if (!ensureMsgf(WIIUSE_USING_IR(Wiimote), TEXT("Controller not using IR"))) return;

	OutResult_ = FVector2D(Wiimote->ir.vres[0], Wiimote->ir.vres[1]);
}

void FWiimoteInputDevice::SetMotionPlusEnabled(int32 ControllerId, bool IsEnabled)
{
    if (GWiimotes[ControllerId] == nullptr)
        return;
    if (IsEnabled)
    {
        if (WIIUSE_USING_EXP(GWiimotes[ControllerId]))
        {
            wiiuse_set_motion_plus(GWiimotes[ControllerId], 2);    // nunchuck pass-through
        }
        else
        {
            wiiuse_set_motion_plus(GWiimotes[ControllerId], 1);    // standalone
        }
    }
    else
    {
        wiiuse_set_motion_plus(GWiimotes[ControllerId], 0); // off
    }
}

void FWiimoteInputDevice::SetMotionSensingEnabled(int32 ControllerId, bool IsEnabled)
{
    if (GWiimotes[ControllerId] == nullptr)
        return;
    if (IsEnabled)
    {
        wiiuse_motion_sensing(GWiimotes[ControllerId], 1);
    }
    else
    {
        wiiuse_motion_sensing(GWiimotes[ControllerId], 0);
    }
}

void FWiimoteInputDevice::SetRumbleEnabled(int32 ControllerId, bool IsEnabled)
{
    if (GWiimotes[ControllerId] == nullptr)
        return;
    if (IsEnabled)
    {
        wiiuse_rumble(GWiimotes[ControllerId], 1);
    }
    else
    {
        wiiuse_rumble(GWiimotes[ControllerId], 0);
    }
}

void FWiimoteInputDevice::ScanWiimotes()
{
	int found, connected;
	/*
	*   Initialize an array of wiimote objects.
	*
	*   The parameter is the number of wiimotes I want to create.
	*/
	GWiimotes = wiiuse_init(MAX_WIIMOTES);

	/*
	*   Find wiimote devices
	*
	*   Now we need to find some wiimotes.
	*   Give the function the wiimote array we created, and tell it there
	*   are MAX_WIIMOTES wiimotes we are interested in.
	*
	*   Set the timeout to be 5 seconds.
	*
	*   This will return the number of actual wiimotes that are in discovery mode.
	*/
	found = wiiuse_find(GWiimotes, MAX_WIIMOTES, 5);
	if (!found)
	{
		UE_LOG(LogWiimote, Log, TEXT("No wiimotes found."));
		return;
	}

	/*
	*   Connect to the wiimotes
	*
	*   Now that we found some wiimotes, connect to them.
	*   Give the function the wiimote array and the number
	*   of wiimote devices we found.
	*
	*   This will return the number of established connections to the found wiimotes.
	*/
	connected = wiiuse_connect(GWiimotes, MAX_WIIMOTES);
	if (connected)
	{
		UE_LOG(LogWiimote, Log, TEXT("Connected to %i wiimotes (of %i found)."), connected, found);
	}
	else
	{
		UE_LOG(LogWiimote, Log, TEXT("Failed to connect to any wiimote."));
		return;
	}

	/*
	*   Now set the LEDs and rumble for a second so it's easy
	*   to tell which wiimotes are connected (just like the wii does).
	*/
	wiiuse_set_leds(GWiimotes[0], WIIMOTE_LED_1);
	wiiuse_set_leds(GWiimotes[1], WIIMOTE_LED_2);
	wiiuse_set_leds(GWiimotes[2], WIIMOTE_LED_3);
	wiiuse_set_leds(GWiimotes[3], WIIMOTE_LED_4);

    wiiuse_set_timeout(GWiimotes, MAX_WIIMOTES, 1, 1);
	SetIREnabled(0, true);
	SetMotionSensingEnabled(0, true);
	/*
	UE_LOG(LogWiimote, Log, TEXT("\nControls:"));
	UE_LOG(LogWiimote, Log, TEXT("\tB toggles rumble."));
	UE_LOG(LogWiimote, Log, TEXT("\t+ to start Wiimote accelerometer reporting, - to stop"));
	UE_LOG(LogWiimote, Log, TEXT("\tUP to start IR camera (sensor bar mode), DOWN to stop."));
	UE_LOG(LogWiimote, Log, TEXT("\t1 to start Motion+ reporting, 2 to stop."));
	UE_LOG(LogWiimote, Log, TEXT("\n"));
	*/
	FMemory::Memzero(ControllerStates);
	for (int i = 0; i < MAX_WIIMOTES; ++i)
	{
		ControllerStates[i].ControllerId = i;
		ControllerStates[i].Wiimote = GWiimotes[i];
	}
}
