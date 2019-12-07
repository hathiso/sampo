#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Default_User_Widget.generated.h"

//--------------------------------------------------------------------------------------------------
class UTextBlock;
class UProgressBar;
class UImage;
class UTexture;
//--------------------------------------------------------------------------------------------------

UCLASS(Abstract)
class SAMPO_API UDefault_User_Widget : public UUserWidget
{
	GENERATED_BODY()
protected:
	//--------------------------------------------------------------------------------------------------
	UPROPERTY(meta = (BindWidget))
	UTextBlock* hp_text;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* skill_aa_kd_text;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* skill_1_kd_text;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* skill_2_kd_text;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* skill_base_defense_kd_text;
	UPROPERTY(meta = (BindWidget))
	UProgressBar* hp_progress_bar;
	UPROPERTY(meta = (BindWidget))
	UImage* image_skill_aa;
	UPROPERTY(meta = (BindWidget))
	UImage* image_skill_1;
	UPROPERTY(meta = (BindWidget))
	UImage* image_skill_2;
	UPROPERTY(meta = (BindWidget))
	UImage* image_skill_base_defense;

	UPROPERTY(EditDefaultsOnly)
	UTexture* texture_1;
	UPROPERTY(EditDefaultsOnly)
	UTexture* texture_2;
	UPROPERTY(EditDefaultsOnly)
	UTexture* texture_3;
	UPROPERTY(EditDefaultsOnly)
	UTexture* texture_4;
public:
	//--------------------------------------------------------------------------------------------------
	void NativeConstruct() override;
	void Show_HP_Change(float on_hp_plaeyr, float on_max_hp_plaeyr);
	void Show_Skill_AA_KD_Change(float skill_aa_kd);
	void Show_Skill_1_KD_Change(float skill_1_kd);
	void Show_Skill_2_KD_Change(float skill_2_kd);
	void Show_Skill_Base_Defense_KD_Change(float skill_base_defense_kd);
	FTimerManager& GetWorldTimerManager() const;
	
};
//--------------------------------------------------------------------------------------------------
