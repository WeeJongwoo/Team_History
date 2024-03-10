// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/CNPCMovementPath.h"
#include "Components/SplineComponent.h"

// Sets default values
ACNPCMovementPath::ACNPCMovementPath()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	MovementPath = CreateDefaultSubobject<USplineComponent>(TEXT("Path"));
	MovementPath->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void ACNPCMovementPath::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACNPCMovementPath::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

