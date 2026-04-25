// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/UI_ScoresScreen.h"
#include "Components\Button.h"

void UUI_ScoresScreen::NativeConstruct()
{
	Super::NativeConstruct();

	check(NewGame_Button);
	NewGame_Button->OnClicked.AddDynamic(this, &UUI_ScoresScreen::OnNewGame_Button_Clicked);

	check(BackToMenu_Button);
	BackToMenu_Button->OnClicked.AddDynamic(this, &UUI_ScoresScreen::BackToMenu_Button_Clicked);

}
