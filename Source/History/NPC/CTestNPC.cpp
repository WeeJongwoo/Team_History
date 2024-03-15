// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/CTestNPC.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"


// Sets default values
ACTestNPC::ACTestNPC()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Root"));
	RootComponent = Capsule;
	Capsule->InitCapsuleSize(42.f, 96.f);

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	SkeletalMesh->SetupAttachment(Capsule);
	SkeletalMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -96.0f));
	SkeletalMesh->SetRelativeRotation(FQuat::MakeFromEuler(FVector(0.0f, 0.0f, -90.0f)));

	InteractionSpace = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionSpace"));
	InteractionSpace->InitSphereRadius(300.0f);
	//InteractionSpace->SetCollisionProfileName("NPC");
	//InteractionSpace->OnComponentBeginOverlap(this, );
	//InteractionSpace->OnComponentEndOverlap();
}

	

// Called when the game starts or when spawned
void ACTestNPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACTestNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACTestNPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

