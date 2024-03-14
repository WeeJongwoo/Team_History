// Fill out your copyright notice in the Description page of Project Settings.


#include "Heritage/CHeritageActorBase.h"
#include "UI/CHeritageWidgetComponent.h"
#include "UI/CHeritageInfoWidget.h"
#include "Components/SphereComponent.h"
#include "Gimmick/CStagePassGimmick.h"

// Sets default values
ACHeritageActorBase::ACHeritageActorBase()
{
	InteractiveAreaRadius = 100.0f;
	bIsFirstInteraction = true;

	HeritageMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HeritageMash"));
	RootComponent = HeritageMeshComponent;

	InteractiveArea = CreateDefaultSubobject<USphereComponent>(TEXT("HeritageArea"));
	InteractiveArea->SetupAttachment(RootComponent);
	InteractiveArea->SetSphereRadius(InteractiveAreaRadius);
	InteractiveArea->OnComponentBeginOverlap.AddDynamic(this, &ACHeritageActorBase::OnInteractionTriggerBeginOverlap);
	InteractiveArea->OnComponentEndOverlap.AddDynamic(this, &ACHeritageActorBase::OnInteractionTriggerEndOverlap);

	HeritageInfo = CreateDefaultSubobject<UCHeritageWidgetComponent>(TEXT("HeritageInfo"));
	HeritageInfo->SetupAttachment(RootComponent);

	static ConstructorHelpers::FClassFinder<UCHeritageInfoWidget> HeritageInfoWidgetRef(TEXT("/Game/Project_History/UI/WB_HeritageInfo.WB_HeritageInfo_C"));
	if (HeritageInfoWidgetRef.Class)
	{
		HeritageInfo->SetWidgetClass(HeritageInfoWidgetRef.Class);
		HeritageInfo->SetWidgetSpace(EWidgetSpace::Screen);
		HeritageInfo->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	static ConstructorHelpers::FObjectFinder<ACStagePassGimmick> StagePassGimmickRef(TEXT("/Game/Project_History/Gimmick/BP_StagePassGimmick.BP_StagePassGimmick"));
	if (StagePassGimmickRef.Object)
	{
		StagePassGimmick = StagePassGimmickRef.Object;
	}
}

// Called when the game starts or when spawned
void ACHeritageActorBase::BeginPlay()
{
	Super::BeginPlay();

	HeritageInfo->SetVisibility(false);
}

void ACHeritageActorBase::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	InteractiveArea->SetSphereRadius(InteractiveAreaRadius);
}

void ACHeritageActorBase::OnInteractionTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	InteractHeritage();
}

void ACHeritageActorBase::OnInteractionTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Log, TEXT("End Overlap"));

	HeritageInfo->SetVisibility(false);
}

void ACHeritageActorBase::InteractHeritage()
{
	if (bIsFirstInteraction == true)
	{
		UE_LOG(LogTemp, Log, TEXT("First OnInteractionTriggerBeginOverlap"));
		bIsFirstInteraction = false;

		ACStagePassGimmick* StageGimmick = Cast<ACStagePassGimmick>(StagePassGimmick);
		if (StageGimmick != nullptr) 
		{
			UE_LOG(LogTemp, Log, TEXT("Increasing"));
			StageGimmick->IncreaseCount();
		}
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("OnInteractionTriggerBeginOverlap"));
	}
	HeritageInfo->SetVisibility(true);
}

