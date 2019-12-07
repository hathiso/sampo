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
	UPROPERTY(EditDefaultsOnly, meta = (BindComponent)) class UBoxComponent* box_skill_colision;
	UPROPERTY(EditDefaultsOnly) TSubclassOf<class ADefault_Projectile_Actor> projctail;
	FTimerHandle skill_aa_timer;
	FTimerHandle skill_1_timer;
	FTimerHandle skill_2_timer;
	FTimerHandle skill_base_defense_timer;
	FTimerHandle status_parrying_timer;
	FTimerHandle show_skill_aa_timer;
	FTimerHandle show_skill_1_timer;
	FTimerHandle show_skill_2_timer;
	FTimerHandle show_skill_base_defense_timer;
	UPROPERTY(EditDefaultsOnly, Category = "status") bool status_parrying = false;
	UPROPERTY(EditDefaultsOnly, Category = "status") float status_parrying_duration = 0.7f;
	UPROPERTY(EditDefaultsOnly, Category = "Skill_KD") float skill_aa_kd;
	UPROPERTY(EditDefaultsOnly, Category = "Skill_KD") float skill_1_kd = 10;
	UPROPERTY(EditDefaultsOnly, Category = "Skill_KD") float skill_2_kd;
	UPROPERTY(EditDefaultsOnly, Category = "Skill_KD") float skill_base_defense_kd;
	//-------------------------------------------------------------------------------------------------------------------------------------------
	UFUNCTION() virtual void Skill_AA();
	UFUNCTION() virtual void Skill_1();
	UFUNCTION() virtual void Skill_1_KD();
	UFUNCTION() virtual void Skill_2();
	UFUNCTION() virtual void Skill_Base_Defense();
	UFUNCTION() virtual void Skill_Base_Defense_KD();
	UFUNCTION() virtual void Status_Parrying_Duration_Stop();
	UFUNCTION() virtual void Move_Jump();
	UFUNCTION() virtual void Move_RL(const FInputActionValue& value);
	UFUNCTION() virtual void On_Hit_projectile(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void Show_HP_Change(float on_hp_plaeyr, float on_max_hp_plaeyr);
	void Show_Skill_AA_KD_Change(float skill_aa_kd);
	void Show_Skill_1_KD_Change(float skill_1_kd);
	void Show_Skill_2_KD_Change(float skill_2_kd);
	void Show_Skill_Base_Defense_KD_Change(float skill_base_defense_kd);
	//-------------------------------------------------------------------------------------------------------------------------------------------
	Fhp_change on_hp_plaeyr_event;
	FDamage_Out on_damage_out_value;
	FSkill_AA  on_skill_kd_aa_event;
	FSkill_1 on_skill_kd_1_event;
	FSkill_2 on_skill_kd_2_event;
	FSkill_Base_Defense on_skill_kd_base_defense_event;
	//-------------------------------------------------------------------------------------------------------------------------------------------
	virtual Fhp_change& get_hp_plaeyr() override;
	virtual FDamage_Out& get_damage_out() override;
	virtual FSkill_AA& get_skill_aa() override;
	virtual FSkill_1& get_skill_1() override;
	virtual FSkill_2& get_skill_2() override;
	virtual FSkill_Base_Defense& get_skill_base_defense() override;
protected:
	virtual void PostLoad();
	virtual void Tick(float DeltaTime);
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

};
