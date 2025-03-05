// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);


		for (int i = 0; i < TargetLocation.Num(); i++)
		{
			TargetLocation[i] = GetTransform().TransformPosition(TargetLocation[i]);
		}
	}
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TargetLocation.Num() <= 0) return;

	if (HasAuthority())
	{
		FVector Location = GetActorLocation();
		FVector GlobalTargetLocation = TargetLocation[currentTargetIndex];
		FVector Direction = (GlobalTargetLocation - Location).GetSafeNormal();

		Location += Direction * Speed * DeltaTime;
		SetActorLocation(Location);

		if ((GlobalTargetLocation - GetActorLocation()).Length() < 0.2f)
		{
			currentTargetIndex++;
			if (currentTargetIndex >= TargetLocation.Num())
				currentTargetIndex = 0;
		}
	}
}
