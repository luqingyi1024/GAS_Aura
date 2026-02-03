#include "AnimBase.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UAnimBase::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (!TryGetPawnOwner()) return;
	Owner = Cast<ACharacter>(TryGetPawnOwner());
	if (Owner) OwnerMovement = Owner->GetCharacterMovement();
}

void UAnimBase::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	if (!Owner || !OwnerMovement) return;
	GroundSpeed = Owner->GetVelocity().Size2D();
	bIsInAir = OwnerMovement->IsFalling();
}
