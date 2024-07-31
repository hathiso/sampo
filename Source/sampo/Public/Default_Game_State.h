#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Default_Game_State.generated.h"


UCLASS()
class SAMPO_API ADefault_Game_State : public AGameStateBase
{
	GENERATED_BODY()
	ADefault_Game_State();
protected:
	virtual void On_change_stats_damage(float flat_damage_value, float multiplier_out_plaeyr_of_magic_damage, float multiplier_out_plaeyr_of_medicine_damage, float multiplier_out_plaeyr_of_mele_damage, float multiplier_out_plaeyr_of_mex_damage);
};
