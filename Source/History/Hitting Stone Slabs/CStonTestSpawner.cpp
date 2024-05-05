// Fill out your copyright notice in the Description page of Project Settings.


#include "Hitting Stone Slabs/CStonTestSpawner.h"
#include "Components/SplineComponent.h"
#include "CStone.h"

// Sets default values
ACStonTestSpawner::ACStonTestSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnPoints = CreateDefaultSubobject <USplineComponent>(TEXT("SpawnPoints"));

	StoneClass = ACStone::StaticClass();

	NumberOfDawnStones = 0;

}

// Called when the game starts or when spawned
void ACStonTestSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACStonTestSpawner::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	int32 SplineNum = SpawnPoints->GetNumberOfSplinePoints();

	for (int32 i = 0; i < SplineNum; i++)
	{
		FVector SpawnPoint = SpawnPoints->GetLocationAtSplinePoint(i, ESplineCoordinateSpace::World);
		AActor* NewActor = GetWorld()->SpawnActor(StoneClass, &SpawnPoint);
		ACStone* NewStone = Cast<ACStone>(NewActor);
		if (NewStone)
		{
			NewStone->Down.BindUFunction(this, FName("CountDownStone"));
			Targets.Add(NewStone);
		}
	}
}

// Called every frame
void ACStonTestSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (NumberOfDawnStones >= Targets.Num())
		UE_LOG(LogTemp, Log, TEXT("Clear"));
}

void ACStonTestSpawner::CountDownStone()
{
	NumberOfDawnStones++;
}

