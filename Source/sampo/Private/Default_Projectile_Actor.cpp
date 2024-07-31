#include "Default_Projectile_Actor.h"
#include "Components/BoxComponent.h"
#include "Interface/Stats_Character_Interface.h"
#include "GameFramework/ProjectileMovementComponent.h"
//--------------------------------------------------------------------------------------------------

DEFINE_LOG_CATEGORY_STATIC(Projectile_Default, All, All);//VeryVerbose,Verbose,Log,Display,Warning,Error,Fatal
//--------------------------------------------------------------------------------------------------
ADefault_Projectile_Actor::ADefault_Projectile_Actor()
{
	/*IStats_Character_Interface* damage_value = Cast<IStats_Character_Interface>(getOw);
	if (damage_value)
	{
		damage_value->get_damage_out().AddUObject(this, &ThisClass::On_change_stats_damage);
	}
	else
		UE_LOG(Projectile_Default, Error, TEXT("Eroor Owning Player"));*/
	box_projectile_colision = CreateDefaultSubobject<UBoxComponent>(TEXT("box projectile colision"));
	projectile_movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	projectile_movement->InitialSpeed = 300.0f;
	projectile_movement->ProjectileGravityScale = 0.0f;
	UE_LOG(Projectile_Default, Display, TEXT("fdsfdfs"));
}
//--------------------------------------------------------------------------------------------------
void ADefault_Projectile_Actor::BeginPlay()
{
	Super::BeginPlay();
	
}
//--------------------------------------------------------------------------------------------------
void ADefault_Projectile_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//--------------------------------------------------------------------------------------------------
void ADefault_Projectile_Actor::On_change_stats_damage(float flat_damage_value, float multiplier_out_plaeyr_of_magic_damage, float multiplier_out_plaeyr_of_medicine_damage, float multiplier_out_plaeyr_of_mele_damage, float multiplier_out_plaeyr_of_mex_damage)
{
	UE_LOG(Projectile_Default, Display, TEXT("flat_damage_value=%f,multiplier_out_plaeyr_of_magic_damage=%f,multiplier_out_plaeyr_of_medicine_damage=%f,multiplier_out_plaeyr_of_mele_damage=%f,multiplier_out_plaeyr_of_mex_damage=%f"), flat_damage_value, multiplier_out_plaeyr_of_magic_damage, multiplier_out_plaeyr_of_medicine_damage, multiplier_out_plaeyr_of_mele_damage, multiplier_out_plaeyr_of_mex_damage);
	projectile_movement->InitialSpeed = 700.0f;
}

UProjectileMovementComponent* ADefault_Projectile_Actor::get_projectile_movement()
{
	return projectile_movement;
}
