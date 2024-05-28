// Fill out your copyright notice in the Description page of Project Settings.


#include "Hitting Stone Slabs/CStone.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
ACStone::ACStone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StoneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StoneMesh"));
	RootComponent = StoneMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StoneMexhRef(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	if (StoneMexhRef.Object)
	{
		StoneMesh->SetStaticMesh(StoneMexhRef.Object);
	}
	StoneMesh->SetCollisionProfileName(FName("TestObject"));
	StoneMesh->SetSimulatePhysics(true);
	StoneMesh->SetWorldRotation(FRotator(0.f, 90.f, 0.f));
}

// Called when the game starts or when spawned
void ACStone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACStone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (FMath::Abs(GetActorUpVector().Z) <= 0.1)
	{

		if (Down.IsBound())
		{
			Down.Execute();
			Down.Unbind();
		}
	}

}
