// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
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

public:
	virtual void Init() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
	FName StartLevel_Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
	FName MenuLevel_Name;
	
	UFUNCTION()
	void ExecutingMenuCommand(EMenuCommand Command);

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUW_MainMenu> MainMenuClass;

	UFUNCTION(BlueprintCallable)
	void OpenMainMenu();

	UPROPERTY()
	APlayerController* PlayerController;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<USaveGame_Settings> CurrentSettings;

	bool Load_Settings();
	bool Save_Settings();

	FString SettingsSlot_Name = "SettingsSlot";

private:

	UUW_MainMenu* MainMenuWidget;


};
