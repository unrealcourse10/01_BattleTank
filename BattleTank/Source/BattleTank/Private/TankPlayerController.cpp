// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Not Possesenig a Tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Possesenig : %s"), *(ControlledTank->GetName()));
	}
}

//Tick
void ATankPlayerController::Tick(float DeltaTime)
{
	//Super
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector OutHitLocation; //Out Parameter

	if(GetSightRayHitLocation(OutHitLocation)) //Has a "Side-Effect", is going to line trace
	{ 
	UE_LOG(LogTemp, Warning, TEXT("HitLocation : %s"), *OutHitLocation.ToString());

		//TODO tell controlled tank to aim at this point
	}
}

//get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitlocation) const
{
	OutHitlocation = FVector(1.0);
	return true;
}