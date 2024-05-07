// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CStone.generated.h"

DECLARE_DELEGATE(IsDown);

UCLASS()
class HISTORY_API ACStone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACStone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = Mesh)
	TObjectPtr<class UStaticMeshComponent> StoneMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	IsDown Down;
};
