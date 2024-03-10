#include "HeritageInteraction/CHeritageInteractionArea.h"
#include "Components/SphereComponent.h"

UCHeritageInteractionArea::UCHeritageInteractionArea()
{
	AreaRange = 500.0f;

	InteractionTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionArea"));
}

void UCHeritageInteractionArea::BeginPlay()
{
	Super::BeginPlay();

	FVector CurrentLocation = GetOwner()->GetActorLocation();
	/*
	InteractionTrigger->SetupAttachment(GetOwner()->GetRootComponent());
	InteractionTrigger->SetSphereRadius(AreaRange);
	InteractionTrigger->SetRelativeLocation(CurrentLocation);*/

#if ENABLE_DRAW_DEBUG
	//DrawDebugSphere(GetWorld(), CurrentLocation, AreaRange, 32, FColor::Red, false, 100.0f);
#endif

}
