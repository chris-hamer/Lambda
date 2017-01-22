// Fill out your copyright notice in the Description page of Project Settings.

#include "airride.h"
#include "LambdaKart.h"


// Sets default values
ALambdaKart::ALambdaKart()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MC = CreateDefaultSubobject<UVehicleMovementComponent>(TEXT("MovementComponent"));

}

// Called when the game starts or when spawned
void ALambdaKart::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALambdaKart::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	OnTheGround = MC->OnTheGround;
	GroundNormal = MC->GroundNormal;

	MC->UpDirection = UpDirection;

}

// Called to bind functionality to input
void ALambdaKart::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

