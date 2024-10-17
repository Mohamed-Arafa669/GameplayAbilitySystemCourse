// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/EnemyAnimInstanceBase.h"
#include "Characters/EnemyCharacter.h"

void UEnemyAnimInstanceBase::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (EnemyCharacterRef = Cast<AEnemyCharacter>(BaseCharacterRef))
	{
		CharacterMovementRef = EnemyCharacterRef->GetCharacterMovement();
	}
}

void UEnemyAnimInstanceBase::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (EnemyCharacterRef && CharacterMovementRef)
	{

	}
}
