// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CHeritageInteractionArea.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HISTORY_API UCHeritageInteractionArea : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCHeritageInteractionArea();

protected:
	virtual void BeginPlay() override;
	
protected:
	UPROPERTY(EditAnywhere, Category = Area)
	float AreaRange;

	UPROPERTY(VisibleAnywhere, Category = Area)
	TObjectPtr<class USphereComponent> InteractionTrigger;
};
