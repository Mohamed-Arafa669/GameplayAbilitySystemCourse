// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"


class UInputMappingContext;
class UInputAction;
class IInteractInterface;
struct FInputActionValue;
/**
 * 
 */
UCLASS()
class AURA_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
public:
	APlayerControllerBase();
	virtual void PlayerTick(float DeltaTime) override;


protected:

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputMappingContext> PlayerMappingContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	TScriptInterface<IInteractInterface> LastActor;
	TScriptInterface<IInteractInterface> ThisActor;

	void Move(const FInputActionValue& InputActionValue);
	void CursorTrace();

};
