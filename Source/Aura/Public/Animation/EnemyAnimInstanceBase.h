// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstanceBase.h"
#include "EnemyAnimInstanceBase.generated.h"

class AEnemyCharacter;
/**
 * 
 */
UCLASS()
class AURA_API UEnemyAnimInstanceBase : public UAnimInstanceBase
{
	GENERATED_BODY()
protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<AEnemyCharacter> EnemyCharacterRef;
};
