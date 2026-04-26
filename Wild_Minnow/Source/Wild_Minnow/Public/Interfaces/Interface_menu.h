// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interface_menu.generated.h"


UENUM(BlueprintType)
enum class EMenuCommand :uint8
{
	MC_NewGame,
	MC_LoadGame,
	MC_Settings,
	MC_Credits,
	MC_Manual,
	MC_MainMenu,
	MC_Exit,
	NOCOMMAND

};

UENUM(BlueprintType)
enum class ESoundClass :uint8
{
	SC_Master,
	SC_Music,
	SC_GameEffects,
	SC_UIEffects,
	SC_non

};

DECLARE_DELEGATE_OneParam(FOnEnterCommand, EMenuCommand);
DECLARE_DELEGATE_TwoParams(FOnChangedSettings, ESoundClass, float);

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInterface_menu : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WILD_MINNOW_API IInterface_menu
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual FOnEnterCommand& OnEnterCommand() = 0;

	virtual FOnChangedSettings& OnChangedSCVolume() = 0;

	virtual void SetStartValueMasterVolume(bool showPlashScreen,float Master, float Music, float Game, float UI)=0;

	virtual void Convert_to_PauseMenu()= 0;
};
