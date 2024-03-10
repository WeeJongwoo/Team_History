// Fill out your copyright notice in the Description page of Project Settings.


#include "HeritageInteraction/CHeritageInteraction.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ACHeritageInteraction::ACHeritageInteraction()
{
	HeritageMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HeritageStaticMesh"));

	RootComponent = HeritageMesh;

	Offset = FVector::ZeroVector;
	AreaRange = 500.0f;

	InteractionTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionArea"));
	InteractionTrigger->SetupAttachment(RootComponent);
	InteractionTrigger->SetSphereRadius(AreaRange);
	InteractionTrigger->OnComponentBeginOverlap.AddDynamic(this, &ACHeritageInteraction::OnInteractionTriggerBeginOverlap);
}

// Called when the game starts or when spawned
void ACHeritageInteraction::BeginPlay()
{
	Super::BeginPlay();
	

#if ENABLE_DRAW_DEBUG
	DrawDebugSphere(GetWorld(), GetActorLocation(), AreaRange, 32, FColor::Red, false, 100.0f);
#endif
}

void ACHeritageInteraction::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	SetHeritageAreaOffset(Offset);
}

void ACHeritageInteraction::SetHeritageAreaOffset(const FVector OffsetVector)
{
	InteractionTrigger->SetRelativeLocation(OffsetVector);
}

void ACHeritageInteraction::OnInteractionTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("OnInteractionTriggerBeginOverlap"));
}

