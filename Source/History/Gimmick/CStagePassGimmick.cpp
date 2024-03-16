// Fill out your copyright notice in the Description page of Project Settings.


#include "Gimmick/CStagePassGimmick.h"
#include "Components/BoxComponent.h"

// Sets default values
ACStagePassGimmick::ACStagePassGimmick()
{
	CheckpointBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CheckpointArea"));
	CheckpointBox->SetBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	CheckpointBox->OnComponentBeginOverlap.AddDynamic(this, &ACStagePassGimmick::OnCheckpointBoxTriggerBeginOverlap);

	RootComponent = CheckpointBox;

	PassableCount = 1;
	CurrentCount = 0;
}

void ACStagePassGimmick::OnCheckpointBoxTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (CurrentCount < PassableCount)
	{
		UE_LOG(LogTemp, Log, TEXT("OnCheckpointBoxTriggerBeginOverlap : Not yet"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("OnCheckpointBoxTriggerBeginOverlap : Pass"));
	}
}
