#include "Mele_Paper_ZD_Character.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "InputMappingContext.h"

//--------------------------------------------------------------------------------------------------
//AMele_Paper_ZD_Character::AMele_Paper_ZD_Character()
//{
//	PrimaryActorTick.bCanEverTick = true;
//	AutoPossessPlayer = EAutoReceiveInput::Player0;
//}
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
	//Input->BindAction("Move_Jump", IE_Pressed, this, &AMele_Paper_ZD_Character::Move_Jump);
	//InputComponent->BindAxis("Move_RL", this, &AMele_Paper_ZD_Character::Move_RL);
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, "set_input");
}
//--------------------------------------------------------------------------------------------------
//void AMele_Paper_ZD_Character::Move_RL(float AxisValue)
//{
//	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
//	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, "Move");
//}
//--------------------------------------------------------------------------------------------------
void AMele_Paper_ZD_Character::Move_Jump(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, "Jump");
	ACharacter::Jump();
}
//--------------------------------------------------------------------------------------------------