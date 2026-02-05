#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"


AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
	// GetCharacter()->GetCharacterMovement()->bOrientRotationToMovement = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputVector = InputActionValue.Get<FVector2D>();
	const FRotator YawRotator = FRotator(0.f, GetControlRotation().Yaw, 0.f);
	const FVector ForwardVector = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::X);
	const FVector RightVector = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::Y);
	if (APawn* const& ControllerPawn = GetPawn())
	{
		ControllerPawn->AddMovementInput(ForwardVector, InputVector.Y);
		ControllerPawn->AddMovementInput(RightVector, InputVector.X);
	}
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult HitResult{};
	GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
	if (!HitResult.bBlockingHit) return;
	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(HitResult.GetActor());
	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			ThisActor->HighlightActor();
		}else
		{
			
		}
	}else
	{
		if (ThisActor == nullptr)
		{
			LastActor->UnHighlightActor();
		}else
		{
			if (LastActor != ThisActor)
			{
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}else
			{
				
			}
		}
	}
}

// void AAuraPlayerController::Look(const FInputActionValue& InputActionValue)
// {
// 	const FVector2D InputVector = InputActionValue.Get<FVector2D>();
// 	AddYawInput(InputVector.X);
// 	AddPitchInput(InputVector.Y);
// }

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);
	UEnhancedInputLocalPlayerSubsystem* const& Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(AuraContext, 0);
	}
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	FInputModeGameAndUI InputModeData{};
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* const& EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	check(EnhancedInputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
	// EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Look);
}
