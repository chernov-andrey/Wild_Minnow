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
