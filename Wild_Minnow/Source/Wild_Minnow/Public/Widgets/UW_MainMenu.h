// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_MainMenu.generated.h"

class UButton;
class USlider;

UENUM(BlueprintType)
enum class EMenuCommand :uint8
{
	MC_NewGame,
	MC_LoadGame,
	MC_Settings,
	MC_Credits,
	MC_Exit,
	NOCOMMAND

};

UCLASS()
class WILD_MINNOW_API UUW_MainMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnterCommand, EMenuCommand, Command);

protected:

	virtual void NativeConstruct() override;

private:
	// NewGameButton --------------------------------------------------------------------------
	UPROPERTY(meta = (BindWidget))
	UButton* StartNewGameButton;
	
	UFUNCTION()
	void OnStartNewGameButtonClicked();


	//ExitGameButton --------------------------------------------------------------------------
	UPROPERTY(meta = (BindWidget))
	UButton* ExitGameButton;
	
	UFUNCTION()
	void OnExitGameButtonClicked();


	//Sound volume slider --------------------------------------------------------------------------
	UPROPERTY(meta = (BindWidget))
	USlider* SoundVolumeSlider;

	UFUNCTION()
	void OnSoundVolumeSliderChanged(float Value);
};
