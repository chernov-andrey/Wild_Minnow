// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/GameInstance_WM.h"
#include "Kismet\GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/UW_MainMenu.h"
#include "SaveGame_Settings.h"

#include "AudioDevice.h"

void UGameInstance_WM::Init()
{
	Super::Init();
	
#if UE_BUILD_DEBUG || UE_BUILD_DEVELOPMENT
#else
	if (MenuLevel_Name != NAME_None)
	{
		UGameplayStatics::OpenLevel(GetWorld(), MenuLevel_Name);
	}
#endif
	Load_Settings();
}
void UGameInstance_WM::ApplyDefaulSettigs()
{
	if (MasterSoundMix)
	{
		check(GetWorld());
		UGameplayStatics::SetBaseSoundMix(this, MasterSoundMix);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("UGameInstance_WM::OpenMainMenu: MasterSoundMix.IsNull - true"));
	}

	UGameplayStatics::SetSoundMixClassOverride(GetWorld(),
		MasterSoundMix,
		Master_SoundClass,
		CurrentSettings->MasterScaleVolume,      
		1,
		0  
	);
	UGameplayStatics::SetSoundMixClassOverride(GetWorld(),
		MasterSoundMix,
		UI_Effects_SoundClass,
		CurrentSettings->UIEffectVolume,
		1,
		0
	);
	UGameplayStatics::SetSoundMixClassOverride(GetWorld(),
		MasterSoundMix,
		Music_SoundClass,
		CurrentSettings->MusicVolume,
		1,
		0
	);
	UGameplayStatics::SetSoundMixClassOverride(GetWorld(),
		MasterSoundMix,
		Game_Effects_SoundClass,
		CurrentSettings->GameEffectVolume,
		1,
		0
	);
}


void UGameInstance_WM::OpenMainMenu()
{
	ApplyDefaulSettigs();
	check(MainMenuClass);
	MainMenuWidget = CreateWidget<UUW_MainMenu>(this, MainMenuClass);
	MainMenuWidget->AddToViewport();

	check(MainMenuWidget);
	Cast<IInterface_menu>(MainMenuWidget)->SetStartValueMasterVolume(CurrentSettings->MasterScaleVolume, CurrentSettings->MusicVolume, CurrentSettings->GameEffectVolume, CurrentSettings ->UIEffectVolume);
	Cast<IInterface_menu>(MainMenuWidget)->OnEnterCommand().BindUObject(this, &ThisClass::ExecutingMenuCommand);
	Cast<IInterface_menu>(MainMenuWidget)->OnChangedSCVolume().BindUObject(this, &UGameInstance_WM::SetSCVolume);
}

void UGameInstance_WM::SetSCVolume( ESoundClass SC, float NewVolume)
{
	check(CurrentSettings);
	float Volume =FMath::Clamp(NewVolume, 0.002, 1.0);
	
	USoundClass* USC = nullptr;
	switch (SC)
	{
	case ESoundClass::SC_Master:
		CurrentSettings->MasterScaleVolume = Volume;
		USC = Master_SoundClass;
		break;
	case ESoundClass::SC_Music:
		Volume = FMath::Max(0.02,Volume);
		CurrentSettings->MusicVolume = Volume;
		USC = Music_SoundClass;
		break;
	case ESoundClass::SC_GameEffects:
		Volume = FMath::Max(0.01, Volume);
		CurrentSettings->GameEffectVolume = Volume;
		USC = Game_Effects_SoundClass;
		break;
	case ESoundClass::SC_UIEffects:
		Volume = FMath::Max(0.01, Volume);
		CurrentSettings->UIEffectVolume = Volume;
		USC = UI_Effects_SoundClass;
		break;
	case ESoundClass::SC_non:
		UE_LOG(LogTemp, Error, TEXT(" UGameInstance_WM::SetSCVolume: ESoundClass SC - SC_non"));
		break;
	default:
		break;
	}


	if (USC) {
		UGameplayStatics::SetSoundMixClassOverride(GetWorld(),
			MasterSoundMix,
			USC,
			Volume,
			1,
			0.3
		);
	}
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
	Save_Settings();
}
