// Copyright Epic Games, Inc. All Rights Reserved.

#include "ContentAlchemyGameMode.h"
#include "ContentAlchemyCharacter.h"
#include "UObject/ConstructorHelpers.h"
//#include "PG/RoomGenerationRoutine.h"
//#include "PG/AlchemyPlacableSet.h"

AContentAlchemyGameMode::AContentAlchemyGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

//void AContentAlchemyGameMode::GenerateRoom()
//{
//    URoomGenerationRoutine* RoomGenRoutine = NewObject<URoomGenerationRoutine>();
//
//    FAlchemyPlacableSet RoomSet;
//    // Populate RoomSet with floor, wall, and door tiles...
//
//    FVector RoomDimensions(10, 10, 1); // Example: 10x10 grid room
//    TArray<FVector> DoorLocations = { FVector(0, 5, 0), FVector(10, 5, 0) }; // Example door locations at center of two walls
//
//    // Call the Generate function to build the room
//    RoomGenRoutine->Generate(RoomSet, RoomDimensions, DoorLocations);
//}
