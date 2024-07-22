// Fill out your copyright notice in the Description page of Project Settings.


#include "Cass.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

ACass::ACass()
{
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

void ACass::BeginPlay()
{
	Super::BeginPlay();
	
}


void ACass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

