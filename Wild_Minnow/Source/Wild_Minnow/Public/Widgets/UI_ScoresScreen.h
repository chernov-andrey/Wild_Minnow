// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_ScoresScreen.generated.h"


class UButton;
/**
 * 
 */
UCLASS()
class WILD_MINNOW_API UUI_ScoresScreen : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void NativeConstruct()override;

	UPROPERTY(meta = (BindWidget))
	UButton* NewGame_Button;

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewGame_Button_Clicked();

	UPROPERTY(meta = (BindWidget))
	UButton* BackToMenu_Button;

	UFUNCTION(BlueprintImplementableEvent)
	void  BackToMenu_Button_Clicked();

};
