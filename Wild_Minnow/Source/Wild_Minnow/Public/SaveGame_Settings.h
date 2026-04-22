// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveGame_Settings.generated.h"

/**
 * 
 */
UCLASS()
class WILD_MINNOW_API USaveGame_Settings : public USaveGame
{
	GENERATED_BODY()
public:
	UPROPERTY()
	float MasterScaleVolume = 0.5f;
	float MusicVolume = 0.5f;
	float UIEffectVolume = 0.5f;
	float GameEffectVolume = 0.5f;
};
