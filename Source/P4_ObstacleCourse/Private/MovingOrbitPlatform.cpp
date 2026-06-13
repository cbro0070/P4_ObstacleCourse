// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingOrbitPlatform.h"

// Sets default values
AMovingOrbitPlatform::AMovingOrbitPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform Mesh"));
	PlatformMesh->SetupAttachment(RootComponent);
	
	OrbitSpeed = 90.0f;
	OrbitDistance = 30.0f;
	CurrentOrbitAngle = 0.0f;
}

// Called when the game starts or when spawned
void AMovingOrbitPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	TargetActor = 
Cast<AActor>(GetWorld()->GetFirstPlayerController()->
	GetCharacter());
	
}

// Called every frame
void AMovingOrbitPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	CurrentOrbitAngle += DeltaTime * OrbitSpeed;
	if (CurrentOrbitAngle -= 360)
	{
		CurrentOrbitAngle -= 360;
	};
	float Radians = FMath::DegreesToRadians(CurrentOrbitAngle);
	float x = TargetActor->GetActorLocation().X + OrbitDistance * FMath::Cos(Radians);
	float y = TargetActor->GetActorLocation().Y + OrbitDistance * FMath::Sin(Radians);
	SetActorLocation(FVector(x, y, TargetActor->GetActorLocation().Z));
}

