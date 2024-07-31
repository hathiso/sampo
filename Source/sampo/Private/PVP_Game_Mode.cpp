#include "PVP_Game_Mode.h"
#include "Interface/Stats_Character_Interface.h"


DEFINE_LOG_CATEGORY_STATIC(Game_Mode_Default, All, All);//VeryVerbose,Verbose,Log,Display,Warning,Error,Fatal
APVP_Game_Mode::APVP_Game_Mode()
{
	/*IStats_Character_Interface* damage_value = Cast<IStats_Character_Interface>();
	if (damage_value)
	{
		damage_value->get_damage_out().AddUObject(this, &ThisClass::On_change_stats_damage);
	}
	else
		UE_LOG(Game_Mode_Default, Error, TEXT("Eroor Owning Player"));*/
	
}

void APVP_Game_Mode::On_change_stats_damage(float flat_damage_value, float multiplier_out_plaeyr_of_magic_damage,
	float multiplier_out_plaeyr_of_medicine_damage, float multiplier_out_plaeyr_of_mele_damage,
	float multiplier_out_plaeyr_of_mex_damage)
{
	UE_LOG(Game_Mode_Default, Display, TEXT("flat_damage_value=%f,multiplier_out_plaeyr_of_magic_damage=%f,multiplier_out_plaeyr_of_medicine_damage=%f,multiplier_out_plaeyr_of_mele_damage=%f,multiplier_out_plaeyr_of_mex_damage=%f"), flat_damage_value, multiplier_out_plaeyr_of_magic_damage, multiplier_out_plaeyr_of_medicine_damage, multiplier_out_plaeyr_of_mele_damage, multiplier_out_plaeyr_of_mex_damage);
}
