// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Stats_Character_Interface.generated.h"

//--------------------------------------------------------------------------------------------------
DECLARE_MULTICAST_DELEGATE_TwoParams(Fhp_change, float/*on_hp_plaeyr*/, float/*on_max_hp_plaeyr*/);
DECLARE_MULTICAST_DELEGATE_FiveParams(FDamage_Out, float /*flat_damage_value*/, float /*multiplier_out_plaeyr_of_magic_damage*/, float /*multiplier_out_plaeyr_of_medicine_damage*/, float /*multiplier_out_plaeyr_of_mele_damage*/, float /*multiplier_out_plaeyr_of_mex_damage*/);
//--------------------------------------------------------------------------------------------------

UINTERFACE(MinimalAPI)
class UStats_Character_Interface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SAMPO_API IStats_Character_Interface
{
	GENERATED_BODY()

public:
	virtual Fhp_change& get_hp_plaeyr() = 0;
	virtual FDamage_Out& get_damage_out() = 0;

};
