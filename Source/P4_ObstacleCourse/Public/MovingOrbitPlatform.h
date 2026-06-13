// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "MovingOrbitPlatform.generated.h"

UCLASS()
class P4_OBSTACLECOURSE_API AMovingOrbitPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingOrbitPlatform();
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PlatformMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float OrbitSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float OrbitDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentOrbitAngle;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* TargetActor;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
