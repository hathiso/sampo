#include "Default_Game_State.h"
#include "Interface/Stats_Character_Interface.h"
#include "GameFramework/PlayerState.h"

DEFINE_LOG_CATEGORY_STATIC(Game_State_Default, All, All);//VeryVerbose,Verbose,Log,Display,Warning,Error,Fatal
ADefault_Game_State::ADefault_Game_State()
{
/*	
	IStats_Character_Interface* damage_value = Cast<IStats_Character_Interface>();
	if (damage_value)
	{
		damage_value->get_damage_out().AddUObject(this, &ThisClass::On_change_stats_damage);
	}
	else
		UE_LOG(Game_State_Default, Error, TEXT("Eroor Owning Player"));
*/	
}
void ADefault_Game_State::On_change_stats_damage(float flat_damage_value, float multiplier_out_plaeyr_of_magic_damage,
	float multiplier_out_plaeyr_of_medicine_damage, float multiplier_out_plaeyr_of_mele_damage,
	float multiplier_out_plaeyr_of_mex_damage)
{
	UE_LOG(Game_State_Default, Display, TEXT("flat_damage_value=%f,multiplier_out_plaeyr_of_magic_damage = %f,multiplier_out_plaeyr_of_medicine_damage = %f,multiplier_out_plaeyr_of_mele_damage = %f,multiplier_out_plaeyr_of_mex_damage = %f"), flat_damage_value, multiplier_out_plaeyr_of_magic_damage, multiplier_out_plaeyr_of_medicine_damage, multiplier_out_plaeyr_of_mele_damage, multiplier_out_plaeyr_of_mex_damage);
}
