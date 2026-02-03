#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimBase.generated.h"

class UCharacterMovementComponent;
/**
 * 
 */
UCLASS()
class AURA_API UAnimBase : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category="Animation")
	TObjectPtr<ACharacter> Owner{};
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category="Animation")
	TObjectPtr<UCharacterMovementComponent> OwnerMovement{};
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category="Animation")
	float GroundSpeed{};
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category="Animation")
	bool bIsInAir{};
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category="Animation")
	bool bShouldMove{};
};
