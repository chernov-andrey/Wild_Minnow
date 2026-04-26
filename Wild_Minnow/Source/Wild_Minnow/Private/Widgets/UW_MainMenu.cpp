// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/UW_MainMenu.h"
#include "Components/Button.h"
#include "Components/Slider.h"
#include "Widgets/Button_with_Text.h"


FOnEnterCommand& UUW_MainMenu::OnEnterCommand()
{
	return OnEnterCommandEvent;
}

FOnChangedSettings& UUW_MainMenu::OnChangedSCVolume()
{
	return OnChangedSCVolumeEvent;
}

void UUW_MainMenu::SetStartValueMasterVolume(bool showPlashScreen,float Master,float Music, float Game, float UI)
{
	if (showPlashScreen)
	{
		ShowSplashScreen();
	}
	check(MasterVolumeSlider);
	MasterVolumeSlider->SetValue(Master);
	check(MasterVolumeSlider_2);
	MasterVolumeSlider_2->SetValue(Master);

	check(MusicVolumeSlider);
	MusicVolumeSlider->SetValue(Music);

	check(GameEffectsVolumeSlider);
	GameEffectsVolumeSlider->SetValue(Game);

	check(UIEffectsVolumeSlider);
	UIEffectsVolumeSlider->SetValue(UI);
	InitializeComplete();
}


void UUW_MainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	check(StartNewGameButton);
	StartNewGameButton->OnClickButtonEvent.AddDynamic(this,&ThisClass::OnStartNewGameButtonClicked);

	check(LoadGameButton);
	LoadGameButton->OnClickButtonEvent.AddDynamic(this, &ThisClass::OnLoadGameButtonClicked);

	check(ExitGameButton);
	ExitGameButton->OnClickButtonEvent.AddDynamic(this, &ThisClass::OnExitGameButtonClicked);

	check(OpenSettingsButton);
	OpenSettingsButton->OnClickButtonEvent.AddDynamic(this, &ThisClass::OnOpenSettingsButtonClicked);
	
	check(OpenManualButton);
	OpenManualButton->OnClickButtonEvent.AddDynamic(this, &ThisClass::OnOpenManualButtonClicked);
	
	check(MasterVolumeSlider);
	MasterVolumeSlider->OnValueChanged.AddDynamic(this, &ThisClass::OnMasterVolumeSliderChanged);

	check(MasterVolumeSlider_2);
	MasterVolumeSlider_2->OnValueChanged.AddDynamic(this, &ThisClass::OnMasterVolumeSlider_2_Changed);

	check(MusicVolumeSlider);
	MusicVolumeSlider->OnValueChanged.AddDynamic(this, &ThisClass::OnMusicVolumeSliderChanged);

	check(GameEffectsVolumeSlider);
	GameEffectsVolumeSlider->OnValueChanged.AddDynamic(this, &ThisClass::OnGameEffectsVolumeSliderChanged);

	check(UIEffectsVolumeSlider);
	UIEffectsVolumeSlider->OnValueChanged.AddDynamic(this, &ThisClass::OnUIEffectsVolumeSliderChanged);
}

void UUW_MainMenu::OnStartNewGameButtonClicked()
{
	OnEnterCommandEvent.ExecuteIfBound(EMenuCommand::MC_NewGame);
}

void UUW_MainMenu::OnExitGameButtonClicked()
{
	OnEnterCommandEvent.ExecuteIfBound(EMenuCommand::MC_Exit);
}


// master volume -----------------------------------------------------------------------------------------------------------------------------------

void UUW_MainMenu::OnMasterVolumeSliderChanged(float Value)
{
	OnChangedSCVolumeEvent.ExecuteIfBound(ESoundClass::SC_Master, Value);
}

void UUW_MainMenu::OnMasterVolumeSlider_2_Changed(float Value)
{
	OnChangedSCVolumeEvent.ExecuteIfBound(ESoundClass::SC_Master, Value);
}

// other volume -----------------------------------------------------------------------------------------------------------------------------------

void UUW_MainMenu::OnMusicVolumeSliderChanged(float Value)
{
	OnChangedSCVolumeEvent.ExecuteIfBound(ESoundClass::SC_Music, Value);
}

void UUW_MainMenu::OnGameEffectsVolumeSliderChanged(float Value)
{
	OnChangedSCVolumeEvent.ExecuteIfBound(ESoundClass::SC_GameEffects, Value);
}

void UUW_MainMenu::OnUIEffectsVolumeSliderChanged(float Value)
{
	OnChangedSCVolumeEvent.ExecuteIfBound(ESoundClass::SC_UIEffects, Value);
}

