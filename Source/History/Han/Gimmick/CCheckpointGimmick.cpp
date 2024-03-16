// Fill out your copyright notice in the Description page of Project Settings.


#include "Han/Gimmick/CCheckpointGimmick.h"
#include "Components/BoxComponent.h"
#include "Han/GameData/CHistorySingleton.h"

// Sets default values
ACCheckpointGimmick::ACCheckpointGimmick()
{
	CheckpointScale = FVector::OneVector * 100.0f;

	CheckpointBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CheckpointArea"));
	CheckpointBox->SetBoxExtent(CheckpointScale);
	CheckpointBox->OnComponentBeginOverlap.AddDynamic(this, &ACCheckpointGimmick::OnCheckpointBoxTriggerBeginOverlap);

	RootComponent = CheckpointBox;
}

void ACCheckpointGimmick::BeginPlay()
{
	//DrawDebugBox(GetWorld(), GetActorLocation(), CheckpointScale, FColor::Black, false, 1000.0f);
}

void ACCheckpointGimmick::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	CheckpointBox->SetBoxExtent(CheckpointScale);
}

void ACCheckpointGimmick::OnCheckpointBoxTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	uint16 CurrentCount = UCHistorySingleton::Get().GetCurrentInteractionNum();
	uint16 Baseline = UCHistorySingleton::Get().GetInteractionBaseline();
	if (CurrentCount >= Baseline)
	{
		UE_LOG(LogTemp, Log, TEXT("OnCheckpointBoxTriggerBeginOverlap : Pass"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("OnCheckpointBoxTriggerBeginOverlap : Fail"));
	}
}
