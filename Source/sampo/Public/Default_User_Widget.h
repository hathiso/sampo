// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Default_User_Widget.generated.h"
class UTextBlock;
class UProgressBar;
UCLASS(Abstract)
class SAMPO_API UDefault_User_Widget : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* hp_text;
	UPROPERTY(meta = (BindWidget))
	UProgressBar* hp_progress_bar;
	void NativeConstruct() override;
	void Show_HP_Change();
};
