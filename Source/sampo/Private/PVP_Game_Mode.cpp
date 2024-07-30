#include "PVP_Game_Mode.h"
#include "Interface/Stats_Character_Interface.h"

APVP_Game_Mode::APVP_Game_Mode()
{
	IStats_Character_Interface* damage_value = Cast<IStats_Character_Interface>(GetNetOwningPlayer());
	if (damage_value)
	{
		damage_value->get_damage_out().AddUObject(this, &ThisClass::On_change_stats_damage);
	}
	else
		UE_LOG(Projectile_Default, Error, TEXT("Eroor Owning Player"));
}