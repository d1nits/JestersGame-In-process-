// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Cass.generated.h"

UCLASS()
class JESTERGAMES_API ACass : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACass();

	URPROPERTY(VisibleAnyWhere)
		USpringArmComponent* SpringArm;


	URPROPERTY(VisibleAnyWhere)
		UCameraComponent * Camera

	float CharachterStamina;
	bool bIsTired;

	float GetStaminaPercent();
	float AddStamina();
	float DecreaseStamina();

	bool StaminaIsZero();

	UAnimMontage* VertigoAnimation;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
