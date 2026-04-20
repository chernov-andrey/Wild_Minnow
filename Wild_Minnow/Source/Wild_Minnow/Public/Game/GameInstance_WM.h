// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameInstance_WM.generated.h"


class UUW_MainMenu;
/**
 * 
 */
UCLASS()
class WILD_MINNOW_API UGameInstance_WM : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
	FName StartLevel_Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
	FName MenuLevel_Name;
	


};
