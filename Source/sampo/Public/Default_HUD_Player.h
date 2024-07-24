#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Default_HUD_Player.generated.h"


UCLASS(Abstract)
class SAMPO_API ADefault_HUD_Player : public AHUD
{
	GENERATED_BODY()
public:
	ADefault_HUD_Player();
	virtual void BeginPlay();
	UPROPERTY(EditDefaultsOnly, Category = "Widget")
	TSubclassOf <UUserWidget> base_hud;
	

};
