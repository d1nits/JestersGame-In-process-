// Fill out your copyright notice in the Description page of Project Settings.


#include "Cass_Movement.h"



Cass_Movement::~Cass_Movement()
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false; 
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;


	GetCharacterMovement()->bOrientRotationToMovement = true;
	


	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);


	GetCharacterMovement()->JumpZVelocity = 600.f;
	
	GetCharacterMovement()->AirControl = 0.15f;
	

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	

	CameraBoom->TargetArmLength = 100.0f;
	
	CameraBoom->bUsePawnControlRotation = true;
	

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	FollowCamera->bUsePawnControlRotation = false;


}
Cass_Movement::ACass_Movement()
{
}
void Cass_Movement::BeginPlay()
{
	Super::BeginPlay();

}


void Cass_Movement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainChar_Movement::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	
	PlayerInputComponent->BindAxis("Turns", this, &APawn::AddControllerYawInput);


	PlayerInputComponent->BindAxis("LookUporDown", this, &APawn::AddControllerPitchInput);


	PlayerInputComponent->BindAction("JumpUp", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("JumpUp", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &Cass_Movement::MoveForwardorBack);
	PlayerInputComponent->BindAxis("MoveRight", this, &Cass_Movement::MoveRightorLeft);



}



}

void AMainChar_Movement::MoveRightorLeft(float Axis)
{


	FRotator Rotation = Controller->GetControlRotation();

	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);


	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(Direction, Axis);

}
