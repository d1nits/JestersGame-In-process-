// Fill out your copyright notice in the Description page of Project Settings.


#include "Cass.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACass::ACass()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CharachterStamina = 100;

}

float ACass::GeXtStaminaPercent()
{
	return CharachterStamina;
}

float ACass::AddStamina()
{
	return 0.0f;
}

float ACass::DecreaseStamina()
{
	return 0.0f;
}

bool ACass::StaminaIsZero()
{
	if (CharachterStamina <= 0)
	{
		bISTired = true;
		GetCapsuleComponent()->SetColisionEnabled:NoColision();
	}

	return bIsTired;

	UGameplayStatics::SpawnSoundAtLocation(this, TiredSound, GetActorLocation());
}

// Called when the game starts or when spawned
void ACass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

