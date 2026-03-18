// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HorizontalPlatform.generated.h"

UCLASS()
class P4_OBSTACLECOURSE_API AHorizontalPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHorizontalPlatform();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementDistance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
