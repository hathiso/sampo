#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "Interface/Stats_Character_Interface.h"
#include "Mele_Paper_ZD_Character.generated.h"
//-------------------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------------------------------
UCLASS()
class AMele_Paper_ZD_Character : public APaperZDCharacter, public IStats_Character_Interface
{
	GENERATED_BODY()
	AMele_Paper_ZD_Character();
public:
//-------------------------------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditDefaultsOnly, Category = "Stats|HP") float max_hp_plaeyr;
	UPROPERTY(EditDefaultsOnly, Category = "Stats|HP") float hp_plaeyr;
	UPROPERTY(EditDefaultsOnly, Category = "Stats|Damage") float flat_damage_value;
	UPROPERTY(EditDefaultsOnly, Category = "Stats|Multiplier") float multiplier_in_plaeyr_of_magic_damage;
	UPROPERTY(EditDefaultsOnly, Category = "Stats|Multiplier") float multiplier_in_plaeyr_of_medicine_damage;
	UPROPERTY(EditDefaultsOnly, Category = "Stats|Multiplier") float multiplier_in_plaeyr_of_mele_damage;
	UPROPERTY(EditDefaultsOnly, Category = "Stats|Multiplier") float multiplier_in_plaeyr_of_mex_damage;
	UPROPERTY(EditDefaultsOnly, Category = "Stats|Multiplier") float multiplier_out_plaeyr_of_magic_damage;
	UPROPERTY(EditDefaultsOnly, Category = "Stats|Multiplier") float multiplier_out_plaeyr_of_medicine_damage;
	UPROPERTY(EditDefaultsOnly, Category = "Stats|Multiplier") float multiplier_out_plaeyr_of_mele_damage;
	UPROPERTY(EditDefaultsOnly, Category = "Stats|Multiplier") float multiplier_out_plaeyr_of_mex_damage;
	UPROPERTY(EditDefaultsOnly, Category = "Stats|Multiplier") float multiplier_out_plaeyr_of_reload_speed_skill_base;
	UPROPERTY(EditDefaultsOnly, Category = "Stats|Multiplier") float multiplier_out_plaeyr_of_reload_speed_skill_change;
	UPROPERTY(EditDefaultsOnly, Category = "Stats|Multiplier") float multiplier_out_plaeyr_of_reload_speed_skill_all;
	UPROPERTY(EditDefaultsOnly, Category = "EnhancedInput|Context") class UInputMappingContext* Input_Mapping_Context;
	UPROPERTY(EditDefaultsOnly, Category = "EnhancedInput|Action") class UInputAction* Move_Jump_Action;
	UPROPERTY(EditDefaultsOnly, Category = "EnhancedInput|Action") class UInputAction* Move_RL_Action;
	UPROPERTY(EditDefaultsOnly, Category = "EnhancedInput|Action") class UInputAction* Skill_AA_Action;
	UPROPERTY(EditDefaultsOnly, Category = "EnhancedInput|Action") class UInputAction* Skill_1_Action;
	UPROPERTY(EditDefaultsOnly, Category = "EnhancedInput|Action") class UInputAction* Skill_2_Action;
	UPROPERTY(EditDefaultsOnly, Category = "EnhancedInput|Action") class UInputAction* Skill_Base_Defense_Action;
	//UPROPERTY(EditDefaultsOnly, Category = "Default_Projectile") TSubclassOf<class ADefault_Projectile_Actor>  default_projectile_actor;
	UPROPERTY(EditDefaultsOnly,meta = (BindComponent)) class UBoxComponent* box_skill_colision;
	class UWorld* my_world;
	//UPROPERTY(EditDefaultsOnly)
	//TSubclassOf<class ADefault_Projectile_Actor> projctail;
//-------------------------------------------------------------------------------------------------------------------------------------------
	UFUNCTION() virtual void Skill_AA();
	UFUNCTION() virtual void Skill_1();
	UFUNCTION() virtual void Skill_2();
	UFUNCTION() virtual void Skill_Base_Defense();
	UFUNCTION() virtual void Move_Jump();
	UFUNCTION() virtual void Move_RL(const FInputActionValue& value);
	UFUNCTION() virtual void On_Hit_projectile(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
//-------------------------------------------------------------------------------------------------------------------------------------------
	Fhp_change on_hp_plaeyr_event;
	FDamage_Out on_damage_out_value;
//-------------------------------------------------------------------------------------------------------------------------------------------
	virtual Fhp_change& get_hp_plaeyr() override;
	virtual FDamage_Out& get_damage_out() override;
protected:
	virtual void PostLoad();
	virtual void Tick(float DeltaTime);
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

};
