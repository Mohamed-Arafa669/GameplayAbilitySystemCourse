// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimInstanceBase.generated.h"

class UCharacterMovementComponent;
class ACharacterBase;
/**
 * 
 */
UCLASS()
class AURA_API UAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()
protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float GroundSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bShouldMove;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<ACharacterBase> BaseCharacterRef;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCharacterMovementComponent> CharacterMovementRef;

	
};
