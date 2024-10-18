// Copyright Alchemy Wolfe.  All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h" // For TSubclassOf
#include "GameFramework/Actor.h" // For AActor
#include "AlchemyPlacable.generated.h"

/**
 * Struct representing a placable element.
 */
USTRUCT(BlueprintType)
struct FAlchemyPlacable
{
    GENERATED_BODY()

public:
    // Display name for the placable
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ContentAlchemy")
    FString Name;

    // Tags associated with this placable for filtering and categorization
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ContentAlchemy")
    TArray<FName> Tags;

    // Direct reference to the placable Actor class
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ContentAlchemy")
    TSubclassOf<AActor> PlacableClass;

    // Optional: Weight for random selection (useful for future enhancements)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ContentAlchemy")
    float Weight = 1.0f;
};
