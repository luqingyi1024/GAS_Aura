#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraCharacter();

	virtual void PossessedBy(AController* NewController) override;

	virtual void OnRep_PlayerState() override;

private:
	UPROPERTY(EditAnywhere,Category="Camera")
	TObjectPtr<USpringArmComponent> CameraBoom{};
	UPROPERTY(EditAnywhere,Category="Camera")
	TObjectPtr<UCameraComponent> Camera{};
	
	void InitAbilityActorInfo();
};
