#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Stats_Character_Interface_Test.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(Fhp_change, float, on_hp_plaeyr);

UINTERFACE(MinimalAPI)
class UStats_Character_Interface_Test : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SAMPO_API IStats_Character_Interface_Test
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual Fhp_change& get_hp_plaeyr() = 0;
};
