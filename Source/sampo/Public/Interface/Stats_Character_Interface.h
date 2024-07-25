// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Stats_Character_Interface.generated.h"

//--------------------------------------------------------------------------------------------------
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(Fhp_change, float, on_hp_plaeyr);
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

};
