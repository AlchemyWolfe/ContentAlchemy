// Copyright Alchemy Wolfe.  All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AlchemyPlacable.h"
#include "AlchemyPlacableDatabase.generated.h"

/**
 * Data Asset containing a list of placable elements for procedural generation.
 * This is meant to be a subset of total assets in the game that relate to each other,
 * possibly tagged by environment or usage.
 */
UCLASS(BlueprintType)
class CONTENTALCHEMY_API UAlchemyPlacableDatabase : public UDataAsset
{
    GENERATED_BODY()

public:
    // Tags associated with this placable for filtering and categorization
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ContentAlchemy")
    TArray<FName> Tags;

    // Array of placable entries
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ContentAlchemy")
    TArray<FAlchemyPlacable> Placables;

    // Get AlchemyPlacables that must have all required tags
    TArray<FAlchemyPlacable*> GetPlacablesByRequiredTags(const TArray<FName>& RequiredTags) const;

    // Get AlchemyPlacables that have any of these tags
    TArray<FAlchemyPlacable*> GetPlacablesByAnyTags(const TArray<FName>& AnyOfTags) const;

    // Get AlchemyPlacables that have this tag
    TArray<FAlchemyPlacable*> GetPlacablesByTag(const FName& Tag) const;
};
