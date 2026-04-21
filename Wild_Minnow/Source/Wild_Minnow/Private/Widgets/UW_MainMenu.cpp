// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/UW_MainMenu.h"
#include "Components/Button.h"
#include "Components/Slider.h"

void UUW_MainMenu::LoadSettings(float MasterVolume)
{
	check(SoundVolumeSlider);
	SoundVolumeSlider->SetValue(MasterVolume);
}

void UUW_MainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	check(StartNewGameButton);
	StartNewGameButton->OnClicked.AddDynamic(this,&ThisClass::OnStartNewGameButtonClicked);

	check(ExitGameButton);
	ExitGameButton->OnClicked.AddDynamic(this, &ThisClass::OnExitGameButtonClicked);
	
	check(OpenManualButton);
	OpenManualButton->OnClicked.AddDynamic(this, &ThisClass::OnOpenManualButtonClicked);
	
	check(SoundVolumeSlider);
	SoundVolumeSlider->OnValueChanged.AddDynamic(this, &ThisClass::OnSoundVolumeSliderChanged);
}

void UUW_MainMenu::OnStartNewGameButtonClicked()
{
	OnEnterCommandEvent.Broadcast(EMenuCommand::MC_NewGame);
}

void UUW_MainMenu::OnExitGameButtonClicked()
{
	OnEnterCommandEvent.Broadcast(EMenuCommand::MC_Exit);
}

void UUW_MainMenu::OnSoundVolumeSliderChanged(float Value)
{
	OnEnterCommandEvent.Broadcast(EMenuCommand::NOCOMMAND);
}

void UUW_MainMenu::OnOpenManualButtonClicked()
{
	OnEnterCommandEvent.Broadcast(EMenuCommand::MC_Manual);
}

