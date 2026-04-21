// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/GameInstance_WM.h"
#include "Kismet\GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/UW_MainMenu.h"

#include "SaveGame_Settings.h"


void UGameInstance_WM::Init()
{
#if UE_BUILD_DEBUG || UE_BUILD_DEVELOPMENT
#else
	if (MenuLevel_Name != "") 
	{
		UGameplayStatics::OpenLevel(GetWorld(), MenuLevel_Name);
	}
#endif

	Load_Settings();
	Super::Init();
}

void UGameInstance_WM::OpenMainMenu()
{
	check(MainMenuClass);
	MainMenuWidget = CreateWidget<UUW_MainMenu>(this, MainMenuClass);
	MainMenuWidget->AddToViewport();

	check(MainMenuWidget);
	MainMenuWidget->OnEnterCommandEvent.AddDynamic(this, &ThisClass::ExecutingMenuCommand);
	MainMenuWidget->LoadSettings(CurrentSettings->MasterVolume);
}

bool UGameInstance_WM::Load_Settings()
{
	CurrentSettings = Cast<USaveGame_Settings>(UGameplayStatics::LoadGameFromSlot(SettingsSlot_Name, 0));

	if (CurrentSettings)
	{
		UE_LOG(LogTemp,Log,TEXT("SaveSettings loaded successfully!"));
		return true;	
	}

	CurrentSettings = Cast<USaveGame_Settings>(UGameplayStatics::CreateSaveGameObject(USaveGame_Settings::StaticClass()));
	if (CurrentSettings)
	{
		UE_LOG(LogTemp, Log, TEXT("New SaveSettings created!"));
		return true;
	}

	UE_LOG(LogTemp, Error, TEXT("Failed to load or create save game"));
	return false;
}

bool UGameInstance_WM::Save_Settings()
{
	if (!CurrentSettings)
	{
		UE_LOG(LogTemp, Warning, TEXT("No save game instance to save"));
		return false;
	}

	bool bSuccess = UGameplayStatics::SaveGameToSlot(CurrentSettings, SettingsSlot_Name, 0);
	if (bSuccess)
	{
		UE_LOG(LogTemp, Log, TEXT("Game saved successfully"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to save game"));
	}
	return bSuccess;
}

void UGameInstance_WM::ExecutingMenuCommand(EMenuCommand Command)
{
	switch (Command)
	{
	case EMenuCommand::MC_NewGame:
		UGameplayStatics::OpenLevel(GetWorld(), StartLevel_Name);
		MainMenuWidget->RemoveFromParent();
		break;
	case EMenuCommand::MC_LoadGame:

		break;
	case EMenuCommand::MC_Settings:

		break;
	case EMenuCommand::MC_Credits:

		break;
	case EMenuCommand::MC_Manual:

		break;
	case EMenuCommand::MC_Exit:
		PlayerController->ConsoleCommand("quit");
		break;
	case EMenuCommand::NOCOMMAND:
		break;
	default:
		break;
	}

}
