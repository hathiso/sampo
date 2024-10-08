#include "Mele_Paper_ZD_Character.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "Default_Projectile_Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "InputMappingContext.h"
#include "Components/BoxComponent.h"
DEFINE_LOG_CATEGORY_STATIC(Plaeyr_Default, All, All);//VeryVerbose,Verbose,Log,Display,Warning,Error,Fatal
//-------------------------------------------------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------------------------------------------------
AMele_Paper_ZD_Character::AMele_Paper_ZD_Character()
{
	//box_skill_colision = CreateDefaultSubobject<UBoxComponent>(TEXT("box_skill"));
	//check(box_skill_colision);
	//box_skill_colision->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::On_Hit_projectile);
}
//-------------------------------------------------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::PostLoad()
{
	Super::PostLoad();

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	UE_LOG(Plaeyr_Default, Display, TEXT("On_PostLoad_Plaeyr"));
}
//-------------------------------------------------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//LocStart = GetActorLocation();
	//LocStart.X = GetActorLocation().X + 10;
	////LocMele.Y = 0;
	//SetActorLocation(LocStart);
}
//-------------------------------------------------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	APlayerController* PlayerController = Cast<APlayerController>(GetController());

	UEnhancedInputLocalPlayerSubsystem* sub_system_input = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());

	sub_system_input->ClearAllMappings();
	sub_system_input->AddMappingContext(Input_Mapping_Context, 0);

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	Input->BindAction(Move_Jump_Action, ETriggerEvent::Triggered, this, &AMele_Paper_ZD_Character::Move_Jump);
	Input->BindAction(Move_RL_Action, ETriggerEvent::Triggered, this, &AMele_Paper_ZD_Character::Move_RL);
	Input->BindAction(Skill_AA_Action, ETriggerEvent::Triggered, this, &AMele_Paper_ZD_Character::Skill_AA);
	Input->BindAction(Skill_1_Action, ETriggerEvent::Triggered, this, &AMele_Paper_ZD_Character::Skill_1);
	Input->BindAction(Skill_2_Action, ETriggerEvent::Triggered, this, &AMele_Paper_ZD_Character::Skill_2);
	Input->BindAction(Skill_Base_Defense_Action, ETriggerEvent::Triggered, this, &AMele_Paper_ZD_Character::Skill_Base_Defense);
	//Input->BindAction("Move_Jump", IE_Pressed, this, &AMele_Paper_ZD_Character::Move_Jump);
	//InputComponent->BindAxis("Move_RL", this, &AMele_Paper_ZD_Character::Move_RL);


	UE_LOG(Plaeyr_Default, Display, TEXT("set_input"));
}
//-------------------------------------------------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::Skill_AA()
{

}
//-------------------------------------------------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::Skill_1()
{
	UE_LOG(Plaeyr_Default, Display, TEXT("On_Skill_1_Plaeyr"));
	on_damage_out_value.Broadcast(flat_damage_value, multiplier_out_plaeyr_of_magic_damage, multiplier_out_plaeyr_of_medicine_damage, multiplier_out_plaeyr_of_mele_damage, multiplier_out_plaeyr_of_mex_damage);
	if (!skill_1_timer.IsValid())
	{
		if (projctail)
		{
			FVector actor_location = GetActorLocation();
			actor_location.X = actor_location.X + 100;
			GetWorld()->SpawnActor<ADefault_Projectile_Actor>(projctail, actor_location, GetActorRotation());
			GetWorldTimerManager().SetTimer(skill_1_timer, this, &ThisClass::Skill_1_KD, skill_1_kd, false);
		}
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::Skill_1_KD()
{
	GetWorld()->GetTimerManager().ClearTimer(skill_1_timer);
	UE_LOG(Plaeyr_Default, Display, TEXT("skill 1 timer Clear"));
}
//-------------------------------------------------------------------------------------------------------------------------------------------




//-------------------------------------------------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::Skill_2()
{

}
//-------------------------------------------------------------------------------------------------------------------------------------------




//-------------------------------------------------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::Skill_Base_Defense()
{
	if (!skill_1_timer.IsValid())
	{
		GetWorldTimerManager().SetTimer(skill_base_defense_timer, this, &ThisClass::Skill_Base_Defense_KD, skill_base_defense_kd, false);
		GetWorldTimerManager().SetTimer(status_parrying_timer, this, &ThisClass::Status_Parrying_Duration_Stop, status_parrying_duration, false);
		status_parrying = true;
		UE_LOG(Plaeyr_Default, Display, TEXT("status_parrying = true"));
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::Skill_Base_Defense_KD()
{
	GetWorld()->GetTimerManager().ClearTimer(skill_base_defense_timer);
	UE_LOG(Plaeyr_Default, Display, TEXT("skill base defense timer Clear"));
}
//-------------------------------------------------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::Status_Parrying_Duration_Stop()
{
	status_parrying = false;
	UE_LOG(Plaeyr_Default, Display, TEXT("status_parrying = false"));
}
//-------------------------------------------------------------------------------------------------------------------------------------------




//-------------------------------------------------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::Move_Jump()
{
	UE_LOG(Plaeyr_Default, Display, TEXT("Jump"));
	hp_plaeyr = hp_plaeyr + 1;
	on_hp_plaeyr_event.Broadcast(hp_plaeyr, max_hp_plaeyr);
	ACharacter::Jump();
}
//-------------------------------------------------------------------------------------------------------------------------------------------




//-------------------------------------------------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::Move_RL(const FInputActionValue& value)
{
	UE_LOG(Plaeyr_Default, Display, TEXT("Move:value"));
	FVector2D move_vector = value.Get<FVector2D>();
	move_vector.Y = move_vector.X * 10;
	AddMovementInput(GetActorForwardVector(), move_vector.Y);

}
//-------------------------------------------------------------------------------------------------------------------------------------------




//-------------------------------------------------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::On_Hit_projectile(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	on_hp_plaeyr_event.Broadcast(hp_plaeyr, max_hp_plaeyr);
}
//-------------------------------------------------------------------------------------------------------------------------------------------




//-------------------------------------------------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::Show_Skill_AA_KD_Change(float skill_aa_kd)
{
	float timer_meter_skill_aa_kd;
	if (show_skill_aa_timer.IsValid())
	{
		GetWorldTimerManager().SetTimer(show_skill_aa_timer, this, &ThisClass::Show_Skill_AA_KD_Change, one_sec, true, 0.0f);
		timer_meter_skill_aa_kd = skill_aa_kd;
	}
	else
		timer_meter_skill_aa_kd = timer_meter_skill_aa_kd - 1;
	if (timer_meter_skill_aa_kd <= 0)
		GetWorldTimerManager().ClearTimer(show_skill_aa_timer);
}
void AMele_Paper_ZD_Character::Show_Skill_1_KD_Change(float skill_1_kd)
{
	float timer_meter_skill_aa_kd;
	if (show_skill_1_timer.IsValid())
	{
		GetWorldTimerManager().SetTimer(show_skill_1_timer, this, &ThisClass::Show_Skill_AA_KD_Change, 1.0f, true, 0.0f);
		timer_meter_skill_aa_kd = skill_1_kd;
	}
	else 
	{
		timer_meter_skill_aa_kd = timer_meter_skill_aa_kd - 1;
		on_skill_kd_aa_event.broadcast(timer_meter_skill_aa_kd);
	}
		if (timer_meter_skill_aa_kd <= 0)
		GetWorldTimerManager().ClearTimer(show_skill_1_timer);
}
void AMele_Paper_ZD_Character::Show_Skill_2_KD_Change(float skill_2_kd)
{
	float timer_meter_skill_aa_kd;
	if (show_skill_aa_timer.IsValid())
	{
		GetWorldTimerManager().SetTimer(show_skill_aa_timer, this, &ThisClass::Show_Skill_AA_KD_Change, one_sec, true, 0.0f);
		timer_meter_skill_aa_kd = skill_aa_kd;
	}
	else
		timer_meter_skill_aa_kd = timer_meter_skill_aa_kd - 1;
	if (timer_meter_skill_aa_kd <= 0)
		GetWorldTimerManager().ClearTimer(show_skill_aa_timer);
}
void AMele_Paper_ZD_Character::Show_Skill_Base_Defense_KD_Change(float skill_base_defense_kd)
{
	float timer_meter_skill_aa_kd;
	if (show_skill_aa_timer.IsValid())
	{
		GetWorldTimerManager().SetTimer(show_skill_aa_timer, this, &ThisClass::Show_Skill_AA_KD_Change, one_sec, true, 0.0f);
		timer_meter_skill_aa_kd = skill_aa_kd;
	}
	else
		timer_meter_skill_aa_kd = timer_meter_skill_aa_kd - 1;
	if (timer_meter_skill_aa_kd <= 0)
		GetWorldTimerManager().ClearTimer(show_skill_aa_timer);
}
//-------------------------------------------------------------------------------------------------------------------------------------------




//-------------------------------------------------------------------------------------------------------------------------------------------
Fhp_change& AMele_Paper_ZD_Character::get_hp_plaeyr()
{
	return on_hp_plaeyr_event;
}
//-------------------------------------------------------------------------------------------------------------------------------------------
FDamage_Out& AMele_Paper_ZD_Character::get_damage_out()
{
	return on_damage_out_value;
}
//-------------------------------------------------------------------------------------------------------------------------------------------
FSkill_AA& AMele_Paper_ZD_Character::get_skill_aa()
{
	return on_skill_kd_aa_event;
}
//-------------------------------------------------------------------------------------------------------------------------------------------
FSkill_1& AMele_Paper_ZD_Character::get_skill_1()
{
	return on_skill_kd_1_event;
}
//-------------------------------------------------------------------------------------------------------------------------------------------
FSkill_2& AMele_Paper_ZD_Character::get_skill_2()
{
	return on_skill_kd_2_event;
}
//-------------------------------------------------------------------------------------------------------------------------------------------
FSkill_Base_Defense& AMele_Paper_ZD_Character::get_skill_base_defense()
{
	return on_skill_kd_base_defense_event;
}
//-------------------------------------------------------------------------------------------------------------------------------------------




//-------------------------------------------------------------------------------------------------------------------------------------------
