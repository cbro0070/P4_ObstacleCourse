// Fill out your copyright notice in the Description page of Project Settings.


#include "LoopingPlatform.h"

#include "VectorTypes.h"

// Sets default values
ALoopingPlatform::ALoopingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MovementSpeed = 100;
	ToleranceThreshold = MovementSpeed/10;
	GoalIndex = 0;
	MaxWaypoints = 4;
	
	
	RootComponent = CreateDefaultSubobject<USceneComponent>
	(TEXT("Root Component"));
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>
	(TEXT("Platform Mesh"));
	PlatformMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ALoopingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALoopingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (SetSpeed == 0)
	{
		SetSpeed = 1;
		AveragedSpeed = FVector::Distance(Waypoints[GoalIndex], GetActorLocation()) / MovementSpeed;
	}
	FVector Direction = Waypoints[GoalIndex] - GetActorLocation();
	Direction.Normalize();
	Direction *= AveragedSpeed * DeltaTime;
	FVector NewLocation = GetActorLocation() + Direction;
	
	if (FVector::Distance(Waypoints[GoalIndex], NewLocation) <= ToleranceThreshold)
	{
		NewLocation = Waypoints[GoalIndex];
		SetSpeed = 0;
		GoalIndex += 1;
		if (GoalIndex == MaxWaypoints)
		{
			GoalIndex = 0;
		}
	}
	SetActorLocation(NewLocation);

}

