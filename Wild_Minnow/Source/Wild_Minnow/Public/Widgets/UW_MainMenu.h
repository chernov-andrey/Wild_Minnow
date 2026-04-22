// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces\Interface_menu.h"
#include "UW_MainMenu.generated.h"

class UButton;
class USlider;


UCLASS()
class WILD_MINNOW_API UUW_MainMenu : public UUserWidget, public IInterface_menu
{
	GENERATED_BODY()
	
public:
	
	//UPROPERTY(BlueprintAssignable)
	FOnEnterCommand OnEnterCommandEvent;
	FOnChangedSettings OnChangedSCVolumeEvent;

	virtual FOnEnterCommand& OnEnterCommand() override;
	virtual FOnChangedSettings& OnChangedSCVolume()override;
	virtual void SetStartValueMasterVolume(float Master, float Music, float Game, float UI) override;

protected:

	virtual void NativeConstruct() override;

private:
	// NewGameButton --------------------------------------------------------------------------
	UPROPERTY(meta = (BindWidget))
	UButton* StartNewGameButton;
	
	UFUNCTION()
	void OnStartNewGameButtonClicked();

	//Open manual Button --------------------------------------------------------------------------
	UPROPERTY(meta = (BindWidget))
	UButton* OpenManualButton;
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnOpenManualButtonClicked();
private:
	//Open Settings Button --------------------------------------------------------------------------
	UPROPERTY(meta = (BindWidget))
	UButton* OpenSettingsButton;
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnOpenSettingsButtonClicked();
private:
	//ExitGameButton --------------------------------------------------------------------------
	UPROPERTY(meta = (BindWidget))
	UButton* ExitGameButton;
	
	UFUNCTION()
	void OnExitGameButtonClicked();

protected:
	//Master volume slider --------------------------------------------------------------------------
	UPROPERTY(BlueprintReadWrite,meta = (BindWidget))
	USlider* MasterVolumeSlider;
private:
	UFUNCTION()
	void OnMasterVolumeSliderChanged(float Value);
protected:
	//Master 2 volume slider --------------------------------------------------------------------------
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	USlider* MasterVolumeSlider_2;
private:
	UFUNCTION()
	void OnMasterVolumeSlider_2_Changed(float Value);



	//Music volume slider --------------------------------------------------------------------------
	UPROPERTY(meta = (BindWidget))
	USlider* MusicVolumeSlider;

	UFUNCTION()
	void OnMusicVolumeSliderChanged(float Value);

	//GameEffects volume slider --------------------------------------------------------------------------
	UPROPERTY(meta = (BindWidget))
	USlider* GameEffectsVolumeSlider;

	UFUNCTION()
	void OnGameEffectsVolumeSliderChanged(float Value);

	//UIEffects volume slider --------------------------------------------------------------------------
	UPROPERTY(meta = (BindWidget))
	USlider* UIEffectsVolumeSlider;

	UFUNCTION()
	void OnUIEffectsVolumeSliderChanged(float Value);

};
