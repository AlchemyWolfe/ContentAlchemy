// Copyright Alchemy Wolfe.  All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AlchemyPlacableDatabase.h"
#include "AlchemyGeneratorDatabase.h"
#include "AlchemyDatabaseManager.generated.h"

/**
 * Data Asset containing a list of AlchemyPlacableDatabases.
 * This is meant to contain all of the databases that are used in the game.
 * Databases under construction and not intended for play should not be here.
 */
UCLASS(BlueprintType)
class CONTENTALCHEMY_API UAlchemyDatabaseManager : public UDataAsset
{
    GENERATED_BODY()

public:
    // A list of all AlchemyPlacableDatabases
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ContentAlchemy")
    TArray<UAlchemyPlacableDatabase*> PlacableDatabases;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ContentAlchemy")
    TArray<UAlchemyGeneratorDatabase*> GeneratorDatabases;

    // Add a database to the manager
    void AddPlacableDatabase(UAlchemyPlacableDatabase* Database);

    // Get a filtered subset of databases based on tags
    UFUNCTION(BlueprintCallable, Category = "ContentAlchemy")
    class UAlchemyPlacableDatabaseSubset* GetDatabasesByRequiredTags(const TArray<FName>& RequiredTags) const;

    // Get a filtered subset of databases based on tags
    UFUNCTION(BlueprintCallable, Category = "ContentAlchemy")
    class UAlchemyPlacableDatabaseSubset* GetDatabasesByAnyTags(const TArray<FName>& AnyOfTags) const;

    // Get a filtered subset of databases based on tags
    UFUNCTION(BlueprintCallable, Category = "ContentAlchemy")
    class UAlchemyPlacableDatabaseSubset* GetDatabasesByTag(const FName& Tag) const;

    // Add a database to the manager
    void AddGeneratorDatabase(UAlchemyGeneratorDatabase* Database);

    UFUNCTION(BlueprintCallable, Category = "ContentAlchemy")
    TArray<FProceduralGeneratorInfo> GetGeneratorsByRequiredTags(const TArray<FName>& RequiredTags) const;

    UFUNCTION(BlueprintCallable, Category = "ContentAlchemy")
    TArray<FProceduralGeneratorInfo> GetGeneratorsByAnyTags(const TArray<FName>& AnyOfTags) const;

    UFUNCTION(BlueprintCallable, Category = "ContentAlchemy")
    TArray<FProceduralGeneratorInfo> GetGeneratorsByTag(const FName& Tag) const;
};
