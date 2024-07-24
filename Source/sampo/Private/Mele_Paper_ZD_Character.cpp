#include "Mele_Paper_ZD_Character.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "Components/BoxComponent.h"

//--------------------------------------------------------------------------------------------------
AMele_Paper_ZD_Character::AMele_Paper_ZD_Character()
{
	//box_skill_colision = CreateDefaultSubobject<UBoxComponent>(TEXT("box_skill"));
	//check(box_skill_colision);
	//box_skill_colision->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::On_Hit_projectile);
}
//--------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::PostLoad()
{
	Super::PostLoad();

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, "On_Spavn_Plaer");
}
//--------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//LocStart = GetActorLocation();
	//LocStart.X = GetActorLocation().X + 10;
	////LocMele.Y = 0;
	//SetActorLocation(LocStart);
}
//--------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	
	UEnhancedInputLocalPlayerSubsystem *sub_system_input = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
	
	sub_system_input->ClearAllMappings();
	sub_system_input->AddMappingContext(Input_Mapping_Context, 0);
	
	UEnhancedInputComponent *Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	
	Input->BindAction(Move_Jump_Action, ETriggerEvent::Triggered, this, &AMele_Paper_ZD_Character::Move_Jump);
	Input->BindAction(Move_RL_Action, ETriggerEvent::Triggered, this, &AMele_Paper_ZD_Character::Move_RL);
	Input->BindAction(Skill_AA_Action, ETriggerEvent::Triggered, this, &AMele_Paper_ZD_Character::Skill_AA);
	Input->BindAction(Skill_1_Action, ETriggerEvent::Triggered, this, &AMele_Paper_ZD_Character::Skill_1);
	Input->BindAction(Skill_2_Action, ETriggerEvent::Triggered, this, &AMele_Paper_ZD_Character::Skill_2);
	Input->BindAction(Skill_BaseDefense_Action, ETriggerEvent::Triggered, this, &AMele_Paper_ZD_Character::Skill_BaseDefense);
	//Input->BindAction("Move_Jump", IE_Pressed, this, &AMele_Paper_ZD_Character::Move_Jump);
	//InputComponent->BindAxis("Move_RL", this, &AMele_Paper_ZD_Character::Move_RL);
	
	
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, "set_input");
}
//--------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::Skill_AA()
{

}
//--------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::Skill_1()
{

}
////--------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::Skill_2()
{

}
//--------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::Skill_BaseDefense()
{

}
//--------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::Move_Jump()
{
	//GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, "Jump");
	
	ACharacter::Jump();
}
//--------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::Move_RL(const FInputActionValue &value)
{
	
	//GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, "Move:value"+value.ToString());

	FVector2D move_vector = value.Get<FVector2D>();
	move_vector.Y = move_vector.X * 10;
	//GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, "Move2:value" + move_vector.ToString());
	AddMovementInput(GetActorForwardVector(), move_vector.Y);
	
}
//--------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::On_Hit_projectile(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "tuch");
	//on_hp_plaeyr_event.Broadcast(hp_plaeyr);
}
//--------------------------------------------------------------------------------------------------
//Fhp_change& AMele_Paper_ZD_Character::get_hp_plaeyr()
//{
//	return on_hp_plaeyr_event;
//}
