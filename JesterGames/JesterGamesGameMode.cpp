// Copyright Epic Games, Inc. All Rights Reserved.

#include "JesterGamesGameMode.h"
#include "JesterGamesCharacter.h"
#include "UObject/ConstructorHelpers.h"

AJesterGamesGameMode::AJesterGamesGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
