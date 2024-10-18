// Copyright Alchemy Wolfe.  All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ProceduralGeneratorInfo.h"
#include "AlchemyGeneratorDatabase.generated.h"

/**
 * Data Asset containing a list of procedural generation routines for procedural generation.
 * This is meant to be tagged by usage, such as "Room".
 */
UCLASS(BlueprintType)
class CONTENTALCHEMY_API UAlchemyGeneratorDatabase : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generators")
    TArray<FProceduralGeneratorInfo> Generators;

    // Get ProceduralGeneratorInfos that must have all required tags
    UFUNCTION(BlueprintCallable, Category = "ContentAlchemy")
    TArray<FProceduralGeneratorInfo> GetGeneratorsByRequiredTags(const TArray<FName>& RequiredTags) const;

    // Get ProceduralGeneratorInfos that have any of these tags
    UFUNCTION(BlueprintCallable, Category = "ContentAlchemy")
    TArray<FProceduralGeneratorInfo> GetGeneratorsByAnyTags(const TArray<FName>& AnyOfTags) const;

    // Get ProceduralGeneratorInfos that have this tag
    UFUNCTION(BlueprintCallable, Category = "ContentAlchemy")
    TArray<FProceduralGeneratorInfo> GetGeneratorsByTag(const FName& Tag) const;
};
