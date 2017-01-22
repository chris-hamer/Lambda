// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PawnMovementComponent.h"
#include "VehicleMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class AIRRIDE_API UVehicleMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()
	
public:

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	bool OnTheGround;

	float SweepSize = 130.0f;
	float SweepDistance = 160.0f;

	float PlayerRadius = 155.0f;

	float MaxSlopeAngle = 45.0f;
	float OffGroundTime;

	FVector UpDirection = FVector::UpVector;

	FVector GroundNormal;
	
};
