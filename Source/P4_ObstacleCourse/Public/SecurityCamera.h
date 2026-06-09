// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "P4_ObstacleCourseCharacter.h"
#include "SecurityCamera.generated.h"

UCLASS()
class P4_OBSTACLECOURSE_API ASecurityCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASecurityCamera();
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* CameraMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ACharacter* TargetCharacter;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
