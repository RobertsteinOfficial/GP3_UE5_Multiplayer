// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Goal.generated.h"

UCLASS()
class MULTIPLAYER_GP3_API AGoal : public AActor
{
	GENERATED_BODY()
	


private: 
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	AGoal();
	
	virtual void Tick(float DeltaTime) override;

};
