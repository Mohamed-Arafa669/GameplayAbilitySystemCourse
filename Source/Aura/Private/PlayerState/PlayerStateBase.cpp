// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerState/PlayerStateBase.h"

#include "AbilitySystem/AbilitySystemComponentBase.h"
#include "AbilitySystem/AttributeSetBase.h"

APlayerStateBase::APlayerStateBase()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponentBase>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UAttributeSetBase>("AttributeSet");

	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* APlayerStateBase::GetAbilitySystemComponent() const
{
	return  AbilitySystemComponent;
}
