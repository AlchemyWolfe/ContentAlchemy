// Copyright Alchemy Wolfe.  All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AlchemyPlacableData.h"
#include "AlchemyPlacableDatabase.generated.h"

/**
 * Data Asset containing a list of placable elements for procedural generation.
 */
UCLASS(BlueprintType)
class CONTENTALCHEMY_API UAlchemyPlacableDatabase : public UDataAsset
{
    GENERATED_BODY()

public:
    // Array of placable entries
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alchemy")
    TArray<FAlchemyPlacableData> Placables;

    // Function to retrieve placables based on required and optional tags
    UFUNCTION(BlueprintCallable, Category = "Alchemy")
    TArray<FAlchemyPlacableData> GetPlacablesByTags(const TArray<FName>& RequiredTags, const TArray<FName>& OptionalTags) const;
};
