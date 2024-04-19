// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Animations/Notifies/AnimNotify_EndSlide.h"

#include "Characters/XyzBaseCharacter.h"

void UAnimNotify_EndSlide::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);
	AXyzBaseCharacter* CharacterOwner = Cast<AXyzBaseCharacter>(MeshComp->GetOwner());
	if (IsValid(CharacterOwner))
	{
		CharacterOwner->StopSlide();
	}
}