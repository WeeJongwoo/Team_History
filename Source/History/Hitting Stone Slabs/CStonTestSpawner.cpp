// Fill out your copyright notice in the Description page of Project Settings.


#include "Hitting Stone Slabs/CStonTestSpawner.h"
#include "Components/SplineComponent.h"

// Sets default values
ACStonTestSpawner::ACStonTestSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnPoints = CreateDefaultSubobject <USplineComponent>(TEXT("SpawnPoints"));



}

// Called when the game starts or when spawned
void ACStonTestSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACStonTestSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

