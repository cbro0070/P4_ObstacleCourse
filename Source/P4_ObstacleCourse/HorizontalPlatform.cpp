// Fill out your copyright notice in the Description page of Project Settings.


#include "HorizontalPlatform.h"

// Sets default values
AHorizontalPlatform::AHorizontalPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHorizontalPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHorizontalPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

