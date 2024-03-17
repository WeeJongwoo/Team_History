// Fill out your copyright notice in the Description page of Project Settings.


#include "Han/Heritage/CHeritageActorBase.h"
#include "Han/UI/CHeritageWidgetComponent.h"
#include "Han/UI/CHeritageInfoWidget.h"
#include "Components/SphereComponent.h"
#include "Han/Gimmick/CCheckpointGimmick.h"
#include "Han/LevelScript/CHistoryLevelScriptActor.h"

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
	HeritageInfo->SetRelativeLocation(FVector(.0f, .0f, 100.f));
	HeritageInfo->SetupAttachment(RootComponent);

	static ConstructorHelpers::FClassFinder<UCHeritageInfoWidget> HeritageInfoWidgetRef(TEXT("/Game/HanJinHo/UI/WB_CHeritageInfo.WB_CHeritageInfo_C"));
	if (HeritageInfoWidgetRef.Class)
	{
		HeritageInfo->SetWidgetClass(HeritageInfoWidgetRef.Class);
		HeritageInfo->SetWidgetSpace(EWidgetSpace::Screen);
		HeritageInfo->SetCollisionEnabled(ECollisionEnabled::NoCollision);
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

		ACHistoryLevelScriptActor* CurrentLevelScript = Cast<ACHistoryLevelScriptActor>(GetWorld()->GetLevelScriptActor());
		if (CurrentLevelScript != nullptr)
		{
			CurrentLevelScript->IncreaseInteractionNum();
		}
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("OnInteractionTriggerBeginOverlap"));
	}
	HeritageInfo->SetVisibility(true);
}

