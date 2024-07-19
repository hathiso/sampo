#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "Mele_Paper_ZD_Character.generated.h"
//#include "InputActionValue.h"

class UInputMappingContext;
//--------------------------------------------------------------------------------------------------
UCLASS()
class SAMPO_API AMele_Paper_ZD_Character : public APaperZDCharacter
{
	GENERATED_BODY()
	FVector LocStart;
public:
	UPROPERTY(EditDefaultsOnly, Category = "EnhancedInput")
	UInputMappingContext* Input_Mapping_Context;
	FVector CurrentVelocity;
	virtual void PostLoad();
	virtual void Tick(float DeltaTime);
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);
	//virtual void Move_RL(float AxisValue);
	UPROPERTY(EditDefaultsOnly, Category = "EnhancedInput")
	class UInputAction* Move_Jump_Action;
	UFUNCTION()
	virtual void Move_Jump(const FInputActionValue& Value);

};
