// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerController_WM.generated.h"

class UUW_MainMenu;
/**
 * 
 */
UCLASS()
class WILD_MINNOW_API APlayerController_WM : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	

};
