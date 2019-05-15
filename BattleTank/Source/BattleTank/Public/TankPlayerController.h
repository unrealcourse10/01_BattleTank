// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //·«“„ ÌﬂÊ‰ ¬Œ— ≈‰ﬂ·Êœ

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:
virtual void BeginPlay() override;
virtual void Tick(float DeltaTime) override;

private:
	ATank * GetControlledTank() const;


	//Start the Tank moving the barrel so that a shot would hit where the crosshair intersects the world
	//privet
	void AimTowardsCrosshair();

	//privet
	//return an out prameter, true if hit landscape 
	bool GetSightRayHitLocation(FVector& OutHitlocation) const;

	UPROPERTY(EditAnyWhere)
		float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnyWhere)
		float CrosshairYLocation = 0.3333;
	
};
