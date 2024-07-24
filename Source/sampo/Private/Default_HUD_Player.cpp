#include "Default_HUD_Player.h"
#include "Blueprint/UserWidget.h"

//--------------------------------------------------------------------------------------------------
ADefault_HUD_Player::ADefault_HUD_Player() : Super()
{

}
//--------------------------------------------------------------------------------------------------
void ADefault_HUD_Player::BeginPlay()
{
	Super::BeginPlay();
	check(base_hud);
	UUserWidget* UMG_Widget = CreateWidget(GetOwningPlayerController(), base_hud);
	if (UMG_Widget) 
	{
		UMG_Widget->AddToViewport();
	}
}
