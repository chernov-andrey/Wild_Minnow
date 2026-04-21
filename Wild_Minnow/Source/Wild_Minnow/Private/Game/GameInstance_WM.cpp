// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/GameInstance_WM.h"
#include "Kismet\GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/UW_MainMenu.h"


void UGameInstance_WM::Init()
{
#if UE_BUILD_DEBUG || UE_BUILD_DEVELOPMENT
#else
	if (MenuLevel_Name != "") 
	{
		UGameplayStatics::OpenLevel(GetWorld(), MenuLevel_Name);
	}
#endif
	Super::Init();
}

void UGameInstance_WM::OpenMainMenu()
{
	check(MainMenuClass);
	MainMenuWidget = CreateWidget<UUW_MainMenu>(this, MainMenuClass);
	MainMenuWidget->AddToViewport();
	check(MainMenuWidget);
	MainMenuWidget->OnEnterCommandEvent.AddDynamic(this, &ThisClass::ExecutingMenuCommand);
}

void UGameInstance_WM::ExecutingMenuCommand(EMenuCommand Command)
{
	switch (Command)
	{
	case EMenuCommand::MC_NewGame:
		UGameplayStatics::OpenLevel(GetWorld(), "Level_1");
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
		MainMenuWidget->RemoveFromParent();
		break;
	case EMenuCommand::NOCOMMAND:
		break;
	default:
		break;
	}

}
