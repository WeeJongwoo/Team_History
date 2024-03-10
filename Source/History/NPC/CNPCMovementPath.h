// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CNPCMovementPath.generated.h"

UCLASS()
class HISTORY_API ACNPCMovementPath : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACNPCMovementPath();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class USplineComponent> MovementPath;

	//TObjectPtr<class> NPC
};
