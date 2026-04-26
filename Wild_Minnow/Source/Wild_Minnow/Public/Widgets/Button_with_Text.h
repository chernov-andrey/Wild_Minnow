// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Button_with_Text.generated.h"

/**
 * 
 */
UCLASS()
class WILD_MINNOW_API UButton_with_Text : public UUserWidget
{

	GENERATED_BODY()
public:	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClickButton);

	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FOnClickButton OnClickButtonEvent;
};
