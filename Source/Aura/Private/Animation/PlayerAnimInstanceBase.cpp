// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/PlayerAnimInstanceBase.h"
#include "Characters/PlayerCharacter.h"

void UPlayerAnimInstanceBase::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (PlayerCharacterRef = Cast<APlayerCharacter>(BaseCharacterRef))
	{
		CharacterMovementRef = PlayerCharacterRef->GetCharacterMovement();
	}
}

void UPlayerAnimInstanceBase::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if(PlayerCharacterRef && CharacterMovementRef)
	{
		if (GroundSpeed > 3.f)
			bShouldMove = true;
		else
			bShouldMove = false;

	}
}
