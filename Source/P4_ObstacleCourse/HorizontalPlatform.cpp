// Fill out your copyright notice in the Description page of Project Settings.


#include "HorizontalPlatform.h"

// Sets default values
AHorizontalPlatform::AHorizontalPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MovementSpeed = 100;
	MovementDistance = 1000;
	ToleranceThreshold = MovementSpeed/10;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>
		(TEXT("Root Component"));
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>
		(TEXT("Platform Mesh"));
	PlatformMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AHorizontalPlatform::BeginPlay()
{
	Super::BeginPlay();
	PreviousStartLocation = GetActorLocation();
	CurrentGoalLocation = GetActorLocation() + FVector(MovementDistance, 0, 0);
}

// Called every frame
void AHorizontalPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector Direction = CurrentGoalLocation - GetActorLocation();
	Direction.Normalize();
	
	Direction *= MovementSpeed * DeltaTime;
	FVector NewLocation = GetActorLocation() + Direction;
	
	if (FVector::Distance(CurrentGoalLocation, NewLocation) <= ToleranceThreshold)
	{
		NewLocation = CurrentGoalLocation;
		CurrentGoalLocation = PreviousStartLocation;
		PreviousStartLocation = NewLocation;
	}
	SetActorLocation(NewLocation);
	

}

