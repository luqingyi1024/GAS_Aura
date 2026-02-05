#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"


class IEnemyInterface;
class UInputAction;
struct FInputActionValue;
class UInputMappingContext;

UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAuraPlayerController();

	virtual void PlayerTick(float DeltaTime) override;

#pragma region  Input
	void Move(const FInputActionValue& InputActionValue);
#pragma endregion
	
	void CursorTrace();

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

private:
#pragma region Input
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"), Category="Input")
	TObjectPtr<UInputMappingContext> AuraContext{};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"), Category="Input")
	TObjectPtr<UInputAction> MoveAction{};
	// UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"), Category="Input")
	// TObjectPtr<UInputAction> LookAction{};
#pragma endregion
	TWeakInterfacePtr<IEnemyInterface> LastActor{};
	TWeakInterfacePtr<IEnemyInterface> ThisActor{};
};
