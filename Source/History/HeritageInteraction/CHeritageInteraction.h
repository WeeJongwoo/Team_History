// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CHeritageInteraction.generated.h"

UCLASS()
class HISTORY_API ACHeritageInteraction : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACHeritageInteraction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	UPROPERTY(VisibleAnywhere, Category = Heritage)
	TObjectPtr<class UStaticMeshComponent> HeritageMesh;

	UPROPERTY(EditAnywhere, Category = Area)
	float AreaRange;

	UPROPERTY(EditAnywhere, Category = Area)
	FVector Offset;

	UPROPERTY(VisibleAnywhere, Category = Area)
	TObjectPtr<class USphereComponent> InteractionTrigger;

protected:
	void SetHeritageAreaOffset(const FVector OffsetVector);

	UFUNCTION()
	void OnInteractionTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
