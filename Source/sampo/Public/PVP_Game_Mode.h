#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "PVP_Game_Mode.generated.h"

UCLASS()
class SAMPO_API APVP_Game_Mode : public AGameMode
{
	GENERATED_BODY()
	APVP_Game_Mode();
protected:
	virtual void On_change_stats_damage(float flat_damage_value, float multiplier_out_plaeyr_of_magic_damage, float multiplier_out_plaeyr_of_medicine_damage, float multiplier_out_plaeyr_of_mele_damage, float multiplier_out_plaeyr_of_mex_damage);
};
