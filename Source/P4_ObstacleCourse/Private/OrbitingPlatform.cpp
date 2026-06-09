// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitingPlatform.h"

// Sets default values
AOrbitingPlatform::AOrbitingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>
	(TEXT("Root Component"));
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>
	(TEXT("Platform Mesh"));
	PlatformMesh->SetupAttachment(RootComponent);
	
	OrbitSpeed = 90.0f;
	OrbitDistance = 4.0f;
	CurrentOrbitAngle = 0.0f;

}

// Called when the game starts or when spawned
void AOrbitingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOrbitingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	CurrentOrbitAngle += DeltaTime * OrbitSpeed;
	if (CurrentOrbitAngle >= 360)
	{
		CurrentOrbitAngle -= 360;
	};
	
	float Radians = FMath::DegreesToRadians(CurrentOrbitAngle);
	
	float x = GetActorLocation().X + OrbitDistance * FMath::Cos(Radians);
	float y = GetActorLocation().Y + OrbitDistance * FMath::Sin(Radians);
	
	SetActorLocation(FVector(x, y, GetActorLocation().Z));

}

