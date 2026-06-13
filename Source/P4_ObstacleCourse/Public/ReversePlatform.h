// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReversePlatform.generated.h"

UCLASS()
class P4_OBSTACLECOURSE_API AReversePlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AReversePlatform();
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PlatformMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ToleranceThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector>Waypoints;
	
	int32 GoalIndex;
	float AveragedSpeed;
	FVector FullDistance;
	int MaxWaypoints;
	bool SetSpeed;
	bool InReverse;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
