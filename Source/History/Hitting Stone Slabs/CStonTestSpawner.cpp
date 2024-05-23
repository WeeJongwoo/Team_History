// Fill out your copyright notice in the Description page of Project Settings.


#include "Hitting Stone Slabs/CStonTestSpawner.h"
#include "Components/SplineComponent.h"
#include "CStone.h"
#include "UI/HistoryStoneHUD.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACStonTestSpawner::ACStonTestSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnPoints = CreateDefaultSubobject <USplineComponent>(TEXT("SpawnPoints"));

	StoneClass = ACStone::StaticClass();

	NumberOfStandingStones = -1;
	LogCount = 0;


	static ConstructorHelpers::FClassFinder<UHistoryStoneHUD> StoneHUDRef(TEXT("/Game/WeeJongWoo/Blueprint/UI/WBP_StoneHUD.WBP_StoneHUD_C"));
	if (StoneHUDRef.Class)
	{
		HistoryStoneHUDClass = StoneHUDRef.Class;
	}
}

// Called when the game starts or when spawned
void ACStonTestSpawner::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	//GetPlayerController(GetWorld(), 0);

	HistoryStoneHUD = CreateWidget<UHistoryStoneHUD>(Controller, HistoryStoneHUDClass);
	if (HistoryStoneHUD)
	{
		HistoryStoneHUD->AddToViewport();
		HistoryStoneHUD->UpdateCount(NumberOfStandingStones);
	}
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

	NumberOfStandingStones = Targets.Num();
}

// Called every frame
void ACStonTestSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (NumberOfStandingStones == 0)
	{
		if (LogCount == 0)
		{
			UE_LOG(LogTemp, Log, TEXT("Clear"));
			LogCount++;
			HistoryStoneHUD->IsClear();
		}
	}
}

void ACStonTestSpawner::CountDownStone()
{
	NumberOfStandingStones--;
	HistoryStoneHUD->UpdateCount(NumberOfStandingStones);
}

