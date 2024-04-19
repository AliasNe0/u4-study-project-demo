// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Equipment/EquipmentItem.h"
#include "Actors/Projectiles/XyzProjectile.h"
#include "ThrowableItem.generated.h"


DECLARE_MULTICAST_DELEGATE(FOnThrowEndEvent)
DECLARE_MULTICAST_DELEGATE(FOnThrowAnimationFinishedEvent)

/**
 *
 */
UCLASS()
class XYZHOMEWORK_API AThrowableItem : public AEquipmentItem
{
	GENERATED_BODY()

public:
	FOnThrowEndEvent OnThrowEndEvent;
	FOnThrowAnimationFinishedEvent OnThrowAnimationFinishedEvent;

	AThrowableItem();
	EWeaponAmmoType GetAmmoType() const { return AmmoType; }
	float GetThrowingWalkSpeed() const { return ThrowingWalkSpeed; }
	bool IsThrowing() const { return bIsThrowing; }
	void Throw();
	void LaunchProjectile() const;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Throwable Parameters | Components")
	UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Throwable Parameters")
	EWeaponAmmoType AmmoType = EWeaponAmmoType::Grenade;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Throwable Parameters")
	TSubclassOf<AXyzProjectile> ProjectileClass = AXyzProjectile::StaticClass();
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Throwable Parameters")
	FName ThrowableSocketName = "ThrowableSocket";
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Throwable Parameters", meta = (ClampMin = -90.f, UIMin = -90.f, ClampMax = 90.f, UIMax = 90.f))
	float LaunchPitchAngle = 30.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Throwable Parameters", meta = (ClampMin = -90.f, UIMin = -90.f, ClampMax = 90.f, UIMax = 90.f))
	float LaunchYawAngle = 0.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Throwable Parameters")
	UAnimMontage* ThrowItemAnimMontage;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Throwable Parameters", meta = (ClampMin = 0.f, UIMin = 0.f))
	float ThrowingWalkSpeed = 150.f;

private:
	FTimerHandle ThrowAnimationTimer;
	bool bIsThrowing = false;

	void OnThrowEnd() const;
	void OnThrowAnimationFinished();
};
