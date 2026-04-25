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
	          
	UFUNCTION(BlueprintImplementableEvent)
	void Convert_to_PauseMenu() override;

protected:

	virtual void NativeConstruct() override;


	// NewGameButton --------------------------------------------------------------------------
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* StartNewGameButton;
	
	UFUNCTION()
	void OnStartNewGameButtonClicked();

	//Open manual Button --------------------------------------------------------------------------
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* OpenManualButton;

	UFUNCTION(BlueprintImplementableEvent)
	void OnOpenManualButtonClicked();


	//Open Settings Button --------------------------------------------------------------------------
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* OpenSettingsButton;

	UFUNCTION(BlueprintImplementableEvent)
	void OnOpenSettingsButtonClicked();

	//LoadGame Button --------------------------------------------------------------------------
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* LoadGameButton;

	UFUNCTION(BlueprintImplementableEvent)
	void OnLoadGameButtonClicked();


	//ExitGameButton --------------------------------------------------------------------------
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* ExitGameButton;
	
	UFUNCTION()
	void OnExitGameButtonClicked();


	//Master volume slider --------------------------------------------------------------------------
	UPROPERTY(BlueprintReadWrite,meta = (BindWidget))
	USlider* MasterVolumeSlider;

	UFUNCTION()
	void OnMasterVolumeSliderChanged(float Value);

	//Master 2 volume slider --------------------------------------------------------------------------
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	USlider* MasterVolumeSlider_2;

	UFUNCTION()
	void OnMasterVolumeSlider_2_Changed(float Value);



	//Music volume slider --------------------------------------------------------------------------
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	USlider* MusicVolumeSlider;

	UFUNCTION()
	void OnMusicVolumeSliderChanged(float Value);

	//GameEffects volume slider --------------------------------------------------------------------------
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	USlider* GameEffectsVolumeSlider;

	UFUNCTION()
	void OnGameEffectsVolumeSliderChanged(float Value);

	//UIEffects volume slider --------------------------------------------------------------------------
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	USlider* UIEffectsVolumeSlider;

	UFUNCTION()
	void OnUIEffectsVolumeSliderChanged(float Value);

};
