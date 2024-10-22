

#include "Characters/CharacterBase.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandASocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void ACharacterBase::DebugCollisionSphere(float frames)
{
    FVector SphereCenter = GetActorLocation();
    float SphereRadius = 100.0f;
    FColor SphereColor = FColor::Red;


    DrawDebugSphere(
        GetWorld(),
        SphereCenter,
        SphereRadius,
        12,
        SphereColor,
        false,
        frames,
        0,
        2.0f
    );
}

void ACharacterBase::DebugAISphere(FVector TargetLocation)
{
    FVector SphereCenter = GetActorLocation();
    float SphereRadius = 200.0f;
    FColor SphereColor = FColor::Green;

    DrawDebugSphere(
        GetWorld(),
        SphereCenter,
        SphereRadius,
        24,
        SphereColor,
        false,
        2.0f,
        0,
        1.0f
    );

    // Draw a line from AI pawn to target location
    DrawDebugLine(
        GetWorld(),
        SphereCenter,
        TargetLocation,
        FColor::Blue,
        false,
        2.0f,
        0,
        1.0f
    );
}

