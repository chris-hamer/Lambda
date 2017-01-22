// Fill out your copyright notice in the Description page of Project Settings.

#include "airride.h"
#include "VehicleMovementComponent.h"



void UVehicleMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector SweepStart = UpdatedComponent->GetComponentLocation();
	FVector SweepEnd = UpdatedComponent->GetComponentLocation() - SweepDistance * UpDirection;

	FHitResult FloorSweepHit;
	FCollisionShape SweepShape = FCollisionShape::MakeBox(FVector(SweepSize, SweepSize, 10.0f));
	GetWorld()->SweepSingleByChannel(FloorSweepHit, SweepStart, SweepEnd, UpdatedComponent->GetComponentQuat(), ECC_Visibility, SweepShape);

	if (!OnTheGround && OffGroundTime > 0.0f) {
		return;
	}

	OnTheGround = false;

	if (FloorSweepHit.bBlockingHit && FloorSweepHit.ImpactNormal.ProjectOnTo(UpDirection).Size() > FMath::Cos((PI / 180.0f)*MaxSlopeAngle)) {
		OnTheGround = true;
		FHitResult temp = FloorSweepHit;
		GetWorld()->LineTraceSingleByChannel(FloorSweepHit, SweepStart, SweepEnd, ECC_Visibility);
		if (!FloorSweepHit.bBlockingHit) {
			FloorSweepHit = temp;
		}
	}

	if (OnTheGround) {
		FVector diff = (FloorSweepHit.ImpactPoint - (SweepStart - PlayerRadius * UpDirection)).ProjectOnTo(UpDirection);

		FHitResult MoveHit;
		SafeMoveUpdatedComponent(diff, UpdatedComponent->GetComponentRotation(), true, MoveHit,ETeleportType::TeleportPhysics);
		SlideAlongSurface(diff, 1.0 - MoveHit.Time, MoveHit.ImpactNormal, MoveHit, true);
	}

	GroundNormal = FloorSweepHit.ImpactNormal;

}

