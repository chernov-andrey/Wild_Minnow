// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces\Interface_menu.h"
#include "GameInstance_WM.generated.h"


class USaveGame_Settings;
class UUW_MainMenu;

/**
 * 
 */
UCLASS()
class WILD_MINNOW_API UGameInstance_WM : public UGameInstance
{
	GENERATED_BODY()
private:
	bool FirstRun = true;

public:
	virtual void Init() override;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClosePauseMenu);
	UPROPERTY(BlueprintAssignable)
	FOnClosePauseMenu FOnClosePauseMenuEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
	FName StartLevel_Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
	FName MenuLevel_Name;
	
	UFUNCTION(BlueprintCallable)
	void ExecutingMenuCommand(EMenuCommand Command);

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUW_MainMenu> MainMenuClass;

	UFUNCTION(BlueprintCallable)
	void OpenMainMenu();

	UFUNCTION(BlueprintCallable)
	void OpenPauseMenu();

	UPROPERTY(BlueprintReadOnly)
	APlayerController* PlayerController;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<USaveGame_Settings> CurrentSettings;

	FString SettingsSlot_Name = "SettingsSlot";

	bool Load_Settings();
	bool Save_Settings();

	void SetSCVolume(ESoundClass SC, float NewVolume);
	void ApplyDefaulSettigs();

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TObjectPtr<USoundMix> MasterSoundMix;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USoundClass* Master_SoundClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USoundClass* UI_Effects_SoundClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USoundClass* Music_SoundClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USoundClass* Game_Effects_SoundClass;
private:

	UUW_MainMenu* MainMenuWidget;
	UUW_MainMenu* PauseMenuWidget;

};
