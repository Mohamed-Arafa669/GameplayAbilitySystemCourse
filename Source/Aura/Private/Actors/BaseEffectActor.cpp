// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/AttributeSetBase.h"

ABaseEffectActor::ABaseEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void ABaseEffectActor::OnBeginOverlap(UPrimitiveComponent* OverlapperComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResults)
{
	// TODO : Change this to apply a gameplay effect. For Now Use const_cast


	if(OtherActor)
	{
		if(IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
		{
			const UAttributeSetBase* MAttributeSet = Cast<UAttributeSetBase>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAttributeSetBase::StaticClass()));

			//Breaking the encapsulation using const cast
			UAttributeSetBase* MutableAttributeSet = const_cast<UAttributeSetBase*>(MAttributeSet);

			MutableAttributeSet->SetHealth(MAttributeSet->GetHealth() + 25.f);

			Destroy();
		}
	}
}

void ABaseEffectActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void ABaseEffectActor::BeginPlay()
{
	Super::BeginPlay();

	if(Sphere)
	{
		Sphere->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);
		Sphere->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnEndOverlap);
	}
}


