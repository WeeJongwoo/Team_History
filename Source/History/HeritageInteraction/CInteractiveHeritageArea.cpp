// Fill out your copyright notice in the Description page of Project Settings.


#include "HeritageInteraction/CInteractiveHeritageArea.h"
#include "UI/CHeritageWidgetComponent.h"

UCInteractiveHeritageArea::UCInteractiveHeritageArea()
{
	bIsFirstInteraction = true;

	HeritageInfo = CreateDefaultSubobject<CHeritageWidgetComponent>(TEXT("HeritageInfo"));
	//static ConstructorHelpers::FClassFinder<UUserWidget> HeritageInfoRef(TEXT(""));

	SphereRadius = 500.0f;
	OnComponentBeginOverlap.AddDynamic(this, &UCInteractiveHeritageArea::OnInteractionTriggerBeginOverlap);
	OnComponentEndOverlap.AddDynamic(this, &UCInteractiveHeritageArea::OnInteractionTriggerEndOverlap);
}

void UCInteractiveHeritageArea::OnInteractionTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	InteractHeritage();
}

void UCInteractiveHeritageArea::OnInteractionTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Log, TEXT("End Overlap"));
}

void UCInteractiveHeritageArea::InteractHeritage()
{
	if (bIsFirstInteraction == true)
	{
		UE_LOG(LogTemp, Log, TEXT("First OnInteractionTriggerBeginOverlap"));
		bIsFirstInteraction = false;

		
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("OnInteractionTriggerBeginOverlap"));
	}
}
