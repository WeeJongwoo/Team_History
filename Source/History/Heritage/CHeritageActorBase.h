// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/HeritageInteractionInterface.h"
#include "CHeritageActorBase.generated.h"

UCLASS()
class HISTORY_API ACHeritageActorBase : public AActor, public IHeritageInteractionInterface
{
	GENERATED_BODY()
	
public:	
	ACHeritageActorBase();

protected:
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

	UFUNCTION()
	void OnInteractionTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnInteractionTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	virtual void InteractHeritage() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Heritage)
	float InteractiveAreaRadius;
	bool bIsFirstInteraction;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = Heritage)
	TObjectPtr<class UStaticMeshComponent> HeritageMeshComponent;
	TObjectPtr<class USphereComponent> InteractiveArea;
	UPROPERTY(VisibleAnywhere, Category = Heritage)
	TObjectPtr<class UCHeritageWidgetComponent> HeritageInfo;

	TObjectPtr<class ACStagePassGimmick> StagePassGimmick;
};
