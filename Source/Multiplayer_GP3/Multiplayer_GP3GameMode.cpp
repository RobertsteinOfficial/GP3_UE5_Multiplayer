// Copyright Epic Games, Inc. All Rights Reserved.

#include "Multiplayer_GP3GameMode.h"
#include "Multiplayer_GP3Character.h"
#include "UObject/ConstructorHelpers.h"

AMultiplayer_GP3GameMode::AMultiplayer_GP3GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
