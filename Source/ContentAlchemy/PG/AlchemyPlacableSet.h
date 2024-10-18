// Copyright Alchemy Wolfe.  All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h" // For TSubclassOf
#include "AlchemyPlacable.h"
#include "AlchemyPlacableSet.generated.h"

/**
 * Struct representing a set of AlchemyPlacable items meant to be used together, such as walls and floors of a lava themed dungeon.
 */
USTRUCT(BlueprintType)
struct FAlchemyPlacableSet
{
    GENERATED_BODY()

    // Items intended to be used together
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ContentAlchemy")
    TArray<FAlchemyPlacable> RelatedItems;

    // Tags associated with this placable for filtering and categorization
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ContentAlchemy")
    TArray<FName> Tags;
};
