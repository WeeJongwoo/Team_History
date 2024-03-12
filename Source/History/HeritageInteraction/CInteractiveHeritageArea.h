// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Interface/HeritageInteractionInterface.h"
#include "CInteractiveHeritageArea.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class HISTORY_API UCInteractiveHeritageArea : public USphereComponent, public IHeritageInteractionInterface
{
	GENERATED_BODY()

public:
	UCInteractiveHeritageArea();

protected:
	UFUNCTION()
	void OnInteractionTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnInteractionTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	virtual void InteractHeritage() override;

protected:
	bool bIsFirstInteraction;

	TObjectPtr<class CHeritageWidgetComponent> HeritageInfo;
};
