// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "VehicleMovementComponent.h"
#include "LambdaKart.generated.h"

UCLASS()
class AIRRIDE_API ALambdaKart : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ALambdaKart();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) UVehicleMovementComponent* MC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector UpDirection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector GroundNormal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool OnTheGround;

};
