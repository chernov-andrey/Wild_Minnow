// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/GameInstance_WM.h"
#include "Kismet\GameplayStatics.h"

void UGameInstance_WM::Init()
{
	if (MenuLevel_Name != "") 
	{
		UGameplayStatics::OpenLevel(GetWorld(), MenuLevel_Name);
	}
	Super::Init();
}
