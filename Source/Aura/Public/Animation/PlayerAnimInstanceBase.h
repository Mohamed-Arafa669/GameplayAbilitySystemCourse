// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstanceBase.h"
#include "PlayerAnimInstanceBase.generated.h"

class APlayerCharacter;
/**
 * 
 */
UCLASS()
class AURA_API UPlayerAnimInstanceBase : public UAnimInstanceBase
{
	GENERATED_BODY()
protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerCharacter> PlayerCharacterRef;
};
