// Fill out your copyright notice in the Description page of Project Settings.

#include "WaypointPlatform.h"
#include "GameFramework/Actor.h"

AWaypointPlatform::AWaypointPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	MovementSpeed = 100;
	ToleranceThreshold = MovementSpeed/10;
	GoalIndex = 0;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>
	(TEXT("Root Component"));
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>
	(TEXT("Platform Mesh"));
	PlatformMesh->SetupAttachment(RootComponent);
}

void AWaypointPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}
	
void AWaypointPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (Waypoints.Num() == 0 || GoalIndex >= Waypoints.Num())
		return;
	
	FVector Direction = Waypoints[GoalIndex] - GetActorLocation();
	Direction.Normalize();
	Direction *= MovementSpeed * DeltaTime;
	FVector NewLocation = GetActorLocation() + Direction;
	
	if (FVector::Distance(Waypoints[GoalIndex], NewLocation) <= ToleranceThreshold)
	{
		NewLocation = Waypoints[GoalIndex];
		GoalIndex++;
	}
	SetActorLocation(NewLocation);
}

AWaypointPlatform::~AWaypointPlatform()
{
}

