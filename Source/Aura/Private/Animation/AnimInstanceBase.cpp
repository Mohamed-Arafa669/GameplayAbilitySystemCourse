// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AnimInstanceBase.h"

#include "Characters/CharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

void UAnimInstanceBase::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if(BaseCharacterRef = Cast<ACharacterBase>(TryGetPawnOwner()))
	{
		CharacterMovementRef = BaseCharacterRef->GetCharacterMovement();
	}
}

void UAnimInstanceBase::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if(BaseCharacterRef && CharacterMovementRef)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(CharacterMovementRef->Velocity);
	}
}
