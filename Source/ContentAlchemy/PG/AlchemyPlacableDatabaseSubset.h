// Copyright Alchemy Wolfe.  All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AlchemyPlacable.h"
#include "AlchemyPlacableDatabase.h"
#include "AlchemyPlacableDatabaseSubset.generated.h"

/**
 * Represents a filtered subset of databases for further queries.
 */
UCLASS(Blueprintable)
class CONTENTALCHEMY_API UAlchemyPlacableDatabaseSubset : public UObject
{
    GENERATED_BODY()

public:
    // Add a database to the subset
    void AddDatabase(UAlchemyPlacableDatabase* Database);

    // Get AlchemyPlacables that must have all required tags from the subset of databases
    TArray<FAlchemyPlacable*> GetPlacablesByRequiredTags(const TArray<FName>& RequiredTags) const;

    // Get AlchemyPlacables that have any of these tags from the subset of databases
    TArray<FAlchemyPlacable*> GetPlacablesByAnyTags(const TArray<FName>& AnyOfTags) const;

    // Get AlchemyPlacables that have this tag from the subset of databases
    TArray<FAlchemyPlacable*> GetPlacablesByTag(const FName& Tag) const;

private:
    TArray<UAlchemyPlacableDatabase*> FilteredDatabases;
};
