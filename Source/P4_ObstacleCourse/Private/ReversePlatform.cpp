// Fill out your copyright notice in the Description page of Project Settings.


#include "ReversePlatform.h"

// Sets default values
AReversePlatform::AReversePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MovementSpeed = 100;
	ToleranceThreshold = MovementSpeed/10;
	GoalIndex = 0;
	MaxWaypoints = 4;
	SetSpeed = true;
	InReverse = false;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>
	(TEXT("Root Component"));
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>
	(TEXT("Platform Mesh"));
	PlatformMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AReversePlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AReversePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (SetSpeed == true)
	{
		SetSpeed = false;
		AveragedSpeed = FVector::Distance(Waypoints[GoalIndex], GetActorLocation()) * MovementSpeed;
	}
	FVector Direction = Waypoints[GoalIndex] - GetActorLocation();
	Direction.Normalize();
	Direction *= AveragedSpeed * DeltaTime;
	FVector NewLocation = GetActorLocation() + Direction;
	
	if (FVector::Distance(Waypoints[GoalIndex], NewLocation) <= ToleranceThreshold)
	{
		NewLocation = Waypoints[GoalIndex];
		SetSpeed = true;
		if (InReverse == false)
		{
			GoalIndex += 1;
		}
		else
		{
			GoalIndex -= 1;
		}
		if (GoalIndex == MaxWaypoints)
		{
			if (InReverse == false)
			{
				InReverse = true;
			}
			else
			{
				InReverse = false;
			}
		}
	}
	SetActorLocation(NewLocation);

}

