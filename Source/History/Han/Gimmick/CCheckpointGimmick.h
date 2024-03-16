// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CCheckpointGimmick.generated.h"

UCLASS()
class HISTORY_API ACCheckpointGimmick : public AActor
{
	GENERATED_BODY()
	
public:	
	ACCheckpointGimmick();

protected:
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

	UFUNCTION()
	void OnCheckpointBoxTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gimmick)
	FVector CheckpointScale;

	TObjectPtr<class UBoxComponent> CheckpointBox;

};
