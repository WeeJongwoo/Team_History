// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CStonTestSpawner.generated.h"

UCLASS()
class HISTORY_API ACStonTestSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACStonTestSpawner();

	virtual void PostInitializeComponents() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<class USplineComponent> SpawnPoints;

	UPROPERTY(EditAnywhere, Category = SpawnTargetActor)
	TSubclassOf<class ACStone> StoneClass;

	UPROPERTY()
	TArray<TObjectPtr<class ACStone>> Targets;
	

	int32 NumberOfDawnStones;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void CountDownStone();
};
