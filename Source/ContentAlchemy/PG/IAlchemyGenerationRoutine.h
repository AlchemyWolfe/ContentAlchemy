// Copyright Alchemy Wolfe.  All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h" // For TSubclassOf
#include "AlchemyPlacableSet.h"
#include "IAlchemyGenerationRoutine.generated.h"

/**
 * Interface for procedural generation routines.
 */
UINTERFACE(MinimalAPI)
class UAlchemyGenerationRoutine : public UInterface
{
    GENERATED_BODY()
};

class IAlchemyGenerationRoutine
{
    GENERATED_BODY()

public:
    virtual void Generate(FAlchemyPlacableSet& RoomSet, const FVector& RoomDimensions, const TArray<FVector>& DoorLocations) = 0;
};