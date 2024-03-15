// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CStagePassGimmick.generated.h"

UCLASS()
class HISTORY_API ACStagePassGimmick : public AActor
{
	GENERATED_BODY()
	
public:	
	ACStagePassGimmick();

	FORCEINLINE void IncreaseCount() { CurrentCount++; }

	UFUNCTION()
	void OnCheckpointBoxTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	UPROPERTY(EditAnywhere, Category = Checkpoint)
	float PassableCount;
	UPROPERTY(VisibleAnywhere, Category = Checkpoint)
	float CurrentCount;

	TObjectPtr<class UBoxComponent> CheckpointBox;
};
