// Fill out your copyright notice in the Description page of Project Settings.


#include "Hitting Stone Slabs/CTestPlayerCharacter.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

// Sets default values
ACTestPlayerCharacter::ACTestPlayerCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	Camera->SetupAttachment(GetCapsuleComponent());
	Camera->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	Camera->bUsePawnControlRotation = true;

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	SkeletalMesh->SetOnlyOwnerSee(true);
	SkeletalMesh->SetupAttachment(Camera);
	SkeletalMesh->bCastDynamicShadow = false;
	SkeletalMesh->CastShadow = false;

	SkeletalMesh->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

	GrapHandle = CreateDefaultSubobject<UPhysicsHandleComponent>(TEXT("GrabHandle"));
	GrapHandle->SetInterpolationSpeed(10.0f);
}

// Called when the game starts or when spawned
void ACTestPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

// Called every frame
void ACTestPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsHit)
	{
		GrapHandle->SetTargetLocation(Camera->GetComponentLocation() + Camera->GetComponentRotation().Vector() * 250.0f);
		UE_LOG(LogTemp, Log, TEXT("%s"), *GrabTarget.GetActor()->GetActorLocation().ToString())
	}
}

// Called to bind functionality to input
void ACTestPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACTestPlayerCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACTestPlayerCharacter::Look);

		EnhancedInputComponent->BindAction(GrabAction, ETriggerEvent::Started, this, &ACTestPlayerCharacter::GrabStart);
		EnhancedInputComponent->BindAction(GrabAction, ETriggerEvent::Completed, this, &ACTestPlayerCharacter::GrabRelese);
	}
}

void ACTestPlayerCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.X);
		AddMovementInput(GetActorRightVector(), MovementVector.Y);
	}
}

void ACTestPlayerCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ACTestPlayerCharacter::GrabStart()
{
	UE_LOG(LogTemp, Log, TEXT("GrabStart"));
	
	FCollisionQueryParams CollisionParams(SCENE_QUERY_STAT(Test), false, this);

	FVector Stert = Camera->GetComponentLocation();
	FVector End = Stert + Camera->GetComponentRotation().Vector() * 500.0f;
	UE_LOG(LogTemp, Log, TEXT("%s / %s"), *Stert.ToString(), *End.ToString());

	IsHit = GetWorld()->LineTraceSingleByChannel(GrabTarget, Stert, End,
		ECollisionChannel::ECC_GameTraceChannel1, CollisionParams);
	if (IsHit)
	{
		UE_LOG(LogTemp, Log, TEXT("%s"), *GrabTarget.GetActor()->GetName());

		GrapHandle->GrabComponentAtLocationWithRotation(GrabTarget.GetComponent(), TEXT("None"), GrabTarget.GetComponent()->GetComponentLocation(), FRotator::ZeroRotator);
	}


}

void ACTestPlayerCharacter::GrabRelese()
{
	UE_LOG(LogTemp, Log, TEXT("GrabEnd"));

	GrapHandle->ReleaseComponent();
	IsHit = false;
}

