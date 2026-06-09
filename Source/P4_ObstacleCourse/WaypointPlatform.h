// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WaypointPlatform.generated.h"
/**
 * 
 */

UCLASS()
class P4_OBSTACLECOURSE_API AWaypointPlatform : public AActor
{
	GENERATED_BODY()
	
public:
	AWaypointPlatform();
	~AWaypointPlatform();
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PlatformMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ToleranceThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector>Waypoints;
	
	int32 GoalIndex;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

