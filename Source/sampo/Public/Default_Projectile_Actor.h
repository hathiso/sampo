#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Default_Projectile_Actor.generated.h"


UCLASS()
class SAMPO_API ADefault_Projectile_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	ADefault_Projectile_Actor();

protected:
	virtual void BeginPlay() override;
	virtual void On_change_stats_damage(float flat_damage_value, float multiplier_out_plaeyr_of_magic_damage, float multiplier_out_plaeyr_of_medicine_damage, float multiplier_out_plaeyr_of_mele_damage, float multiplier_out_plaeyr_of_mex_damage);

public:	
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditDefaultsOnly, meta = (BindComponent))
	class UBoxComponent* box_projectile_colision;
	UPROPERTY(EditDefaultsOnly, meta = (BindComponent))
	class UProjectileMovementComponent* projectile_movement;
};
