// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //���� ���� ��� ������

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank * GetControlledTank() const;

	virtual void BeginPlay() override;
	
	virtual void Tick( float DeltaTime ) override;

	//Start the Tank moving the barrel so that a shot would hit where the crosshair intersects the world
	//privet
	void AimTowardsCrosshair();

	//privet
	//return an out prameter, true if hit landscape 
	bool GetSightRayHitLocation(FVector& OutHitlocation) const;
	
};
