// Copyright Alchemy Wolfe.  All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h" // For TSubclassOf
#include "GameFramework/Actor.h" // For AActor
#include "AlchemyPlacableData.generated.h"

/**
 * Struct representing a placable element in the dungeon.
 */
USTRUCT(BlueprintType)
struct FAlchemyPlacableData
{
    GENERATED_BODY()

public:
    // Display name for the placable
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alchemy")
    FString Name;

    // Tags associated with this placable for filtering and categorization
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alchemy")
    TArray<FName> Tags;

    // Direct reference to the placable Actor class
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alchemy")
    TSubclassOf<AActor> PlacableClass;

    // Optional: Weight for random selection (useful for future enhancements)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alchemy")
    float Weight = 1.0f;
};
