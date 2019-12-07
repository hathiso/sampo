#include "Default_User_Widget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Components/Image.h"
#include "Interface/Stats_Character_Interface.h"

DEFINE_LOG_CATEGORY_STATIC(Wiget_Default,All,All);//VeryVerbose,Verbose,Log,Display,Warning,Error,Fatal
//--------------------------------------------------------------------------------------------------
void UDefault_User_Widget::NativeConstruct()
{
	Super::NativeConstruct();
	IStats_Character_Interface* hp_value = Cast<IStats_Character_Interface>(GetOwningPlayerPawn());
	if (hp_value)
		hp_value->get_hp_plaeyr().AddUObject(this, &ThisClass::Show_HP_Change);
	else
		UE_LOG(Wiget_Default, Error, TEXT("Eroor Owning Player"));
	image_skill_aa->SetVisibility(ESlateVisibility::Hidden);
	if (texture_1)
	image_skill_aa->SetBrushFromSoftTexture(texture_1);
}
FTimerManager& UDefault_User_Widget::GetWorldTimerManager() const
{
	return GetWorld()->GetTimerManager();
}
//--------------------------------------------------------------------------------------------------
void UDefault_User_Widget::Show_HP_Change(float on_hp_plaeyr, float on_max_hp_plaeyr)
{
	UE_LOG(Wiget_Default, Display,TEXT("on_hp_plaeyr = %f"), on_hp_plaeyr);
	UE_LOG(Wiget_Default, Display, TEXT("on_max_hp_plaeyr = %f"), on_max_hp_plaeyr);
	hp_text->SetText(FText::AsNumber(on_hp_plaeyr));
	hp_progress_bar->SetPercent((on_hp_plaeyr/(on_max_hp_plaeyr/100)/100));
	image_skill_aa->SetVisibility(ESlateVisibility::Visible);
}
//--------------------------------------------------------------------------------------------------




//--------------------------------------------------------------------------------------------------
void UDefault_User_Widget::Show_Skill_AA_KD_Change(float skill_aa_kd)
{
	float timer_meter_skill_aa_kd;
	if (show_skill_aa_timer.IsValid())
	{
		GetWorldTimerManager().SetTimer(show_skill_aa_timer, this, &ThisClass::Show_Skill_AA_KD_Change, one_sec, true,0.0f);
		timer_meter_skill_aa_kd = skill_aa_kd;
	}
	else
		timer_meter_skill_aa_kd = timer_meter_skill_aa_kd - 1;
	if(timer_meter_skill_aa_kd<=0)
		GetWorldTimerManager().ClearTimer(show_skill_aa_timer);
}
void UDefault_User_Widget::Show_Skill_1_KD_Change(float skill_1_kd)
{
	//GetWorld()->GetTimerManager().SetTimer(show_skill_1_timer, this, &ThisClass::Show_Skill_AA_KD_Change, 1, true);
}
void UDefault_User_Widget::Show_Skill_2_KD_Change(float skill_2_kd)
{
	//GetWorld()->GetTimerManager().SetTimer(show_skill_1_timer, this, &ThisClass::Show_Skill_AA_KD_Change, 1, true);
}
void UDefault_User_Widget::Show_Skill_Base_Defense_KD_Change(float skill_base_defense_kd)
{
	//GetWorld()->GetTimerManager().SetTimer(show_skill_1_timer, this, &ThisClass::Show_Skill_AA_KD_Change, 1, true);
}
//--------------------------------------------------------------------------------------------------