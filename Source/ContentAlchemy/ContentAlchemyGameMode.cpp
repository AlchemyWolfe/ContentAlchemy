// Copyright Epic Games, Inc. All Rights Reserved.

#include "ContentAlchemyGameMode.h"
#include "ContentAlchemyCharacter.h"
#include "UObject/ConstructorHelpers.h"

AContentAlchemyGameMode::AContentAlchemyGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
