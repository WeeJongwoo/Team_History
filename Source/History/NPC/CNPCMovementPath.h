// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CNPCMovementPath.generated.h"

UENUM()
enum class NPCState : uint8
{
	Move = 0,
	Stop,
	BeginMove
};


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

	UFUNCTION(BlueprintCallable)
	void MoveStop();

	UFUNCTION(BlueprintCallable)
	void Move();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class USplineComponent> MovementPath;

	UPROPERTY(EditDefaultsOnly, Category = "MoveActor")
	TSubclassOf<class AActor> NPCClass;

	AActor* MoveNPC;

	UPROPERTY(EditAnywhere, Category = "MoveActor")
	float TotalPathTimeController;

	//UPROPERTY(EditAnywhere)
	//int32 bSplineInLoop : 1;
	UPROPERTY(EditAnywhere, Category = "MoveActor")
	uint8 bCanMoveNPC : 1;

	float CurrentSplineTime;
	float Distance;
	float DeltaSeconds;
};
