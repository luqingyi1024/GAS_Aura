#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AuraWidgetController.generated.h"

class UAbilitySystemComponent;
class UPlayerState;
class UAttributeSet;
class APlayerController;

USTRUCT(BlueprintType)
struct FAuraWidgetControllerParams
{
	GENERATED_BODY()
	
	FAuraWidgetControllerParams(){}
	FAuraWidgetControllerParams(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
	: PlayerController(PC), PlayerState(PS), AbilitySystemComponent(ASC), AttributeSet(AS)
	{}
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<APlayerController> PlayerController{};
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<APlayerState> PlayerState{};
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent{};
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<UAttributeSet> AttributeSet{};
};

UCLASS()
class AURA_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetControllerParams(const FAuraWidgetControllerParams& WCParams);
	
protected:
	UPROPERTY(BlueprintReadOnly,Category = "WidgetController|Data")
	TObjectPtr<APlayerController> PlayerController{};
	
	UPROPERTY(BlueprintReadOnly,Category = "WidgetController|Data")
	TObjectPtr<APlayerState> PlayerState{};
	
	UPROPERTY(BlueprintReadOnly,Category = "WidgetController|Data")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent{};
	
	UPROPERTY(BlueprintReadOnly,Category = "WidgetController|Data")
	TObjectPtr<UAttributeSet> AttributeSet{};
};
