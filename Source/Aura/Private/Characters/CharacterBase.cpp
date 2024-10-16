

#include "Characters/CharacterBase.h"

ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

