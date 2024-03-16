// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/CNPCMovementPath.h"
#include "Components/SplineComponent.h"

// Sets default values
ACNPCMovementPath::ACNPCMovementPath()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	MovementPath = CreateDefaultSubobject<USplineComponent>(TEXT("Path"));
	MovementPath->SetupAttachment(Root);
	MovementPath->Duration = TotalPathTimeController;
	MovementPath->bDrawDebug = true;
	MovementPath->SetClosedLoop(true);

	TotalPathTimeController = 10.0f;
	//bSplineInLoop = false;

	CurrentSplineTime = 0.0f;
	Distance = 0.0f;

	StopSplineTime = -1.0f;
	StopDistance = -1.0f;

	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACNPCMovementPath::BeginPlay()
{
	Super::BeginPlay();
	
	if (NPCClass != nullptr)
	{
		MoveNPC = GetWorld()->SpawnActor<AActor>(NPCClass, MovementPath->GetComponentTransform());
		if (MoveNPC != nullptr)
		{
			MoveStart();
			bCanMoveNPC = true;
		}
	}
}

// Called every frame
void ACNPCMovementPath::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MoveNPC != nullptr && (bCanMoveNPC))
	{
		CurrentSplineTime = (GetWorld()->GetTimeSeconds() - StartTime) / TotalPathTimeController;
		Distance = MovementPath->GetSplineLength() * CurrentSplineTime;

		FVector Position = MovementPath->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		MoveNPC->SetActorLocation(Position);

		FVector Direction = MovementPath->GetDirectionAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		FRotator Rotator = FRotationMatrix::MakeFromX(Direction).Rotator(); // X축을 Direction 방향으로 돌리는 회전 행렬
		MoveNPC->SetActorRotation(Rotator);

		if (CurrentSplineTime >= 1.0f)
		{
			if (/*bSplineInLoop*/MovementPath->IsClosedLoop())
			{
				bCanMoveNPC = true;

				MoveStart();

				//CurrentSplineTime = (GetWorld()->GetTimeSeconds() - StartTime) / TotalPathTimeController;
				ClearStopData();
			}
		}
	}
}

void ACNPCMovementPath::MoveStart()
{
	StartTime = GetWorld()->GetTimeSeconds();
}

void ACNPCMovementPath::MoveStop(float InCurrentSplineTime, float InDistance)		//NCP와 플레이어 콜리전 시 델리게이트에 바인딩 해 움직임 멈추는 함수 이후 NPC움직임
{
	bCanMoveNPC = false;

	StopSplineTime = CurrentSplineTime;
	StopDistance = Distance;
}

void ACNPCMovementPath::ClearStopData()											// 다시 움직이기 시작할 때 초기화 하는 함수
{
	StopSplineTime = -1.0f;
	StopDistance = -1.0f;
}

