// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/PlayerController_WM.h"
#include "Game/GameInstance_WM.h"

void APlayerController_WM::BeginPlay()
{
	bShowMouseCursor = true;
	Super::BeginPlay();


	UGameInstance_WM* GI = Cast<UGameInstance_WM>(GetGameInstance());
	check(GI);
	GI->PlayerController = this;
}



