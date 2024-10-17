// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/EnemyCharacter.h"
#include "Aura/Aura.h"


AEnemyCharacter::AEnemyCharacter()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	Weapon->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

}

void AEnemyCharacter::HighlightActor()
{
	if (GetMesh())
	{
		GetMesh()->SetRenderCustomDepth(true);
		GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	}

	if (Weapon)
	{
		Weapon->SetRenderCustomDepth(true);
		Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	}
}

void AEnemyCharacter::UnHighlightActor()
{
	if (GetMesh())
		GetMesh()->SetRenderCustomDepth(false);

	if (Weapon)
		Weapon->SetRenderCustomDepth(false);

}
