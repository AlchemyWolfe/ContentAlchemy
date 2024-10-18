// Copyright Alchemy Wolfe.  All Rights Reserved.

#include "AlchemyDatabaseManager.h"
#include "AlchemyPlacableDatabaseSubset.h"

void UAlchemyDatabaseManager::AddPlacableDatabase(UAlchemyPlacableDatabase* Database)
{
    if (Database)
    {
        PlacableDatabases.Add(Database);
    }
}

class UAlchemyPlacableDatabaseSubset* UAlchemyDatabaseManager::GetDatabasesByRequiredTags(const TArray<FName>& RequiredTags) const
{
    UAlchemyPlacableDatabaseSubset* Result = NewObject<UAlchemyPlacableDatabaseSubset>();

    // Filter databases by tags
    for (UAlchemyPlacableDatabase* Database : PlacableDatabases)
    {
        if (!Database)
        {
            continue;
        }

        // Check required tags
        bool bMatchesRequired = true;
        for (const FName& Tag : RequiredTags)
        {
            if (!Database->Tags.Contains(Tag))
            {
                bMatchesRequired = false;
                break;
            }
        }

        if (!bMatchesRequired)
            continue;

        Result->AddDatabase(Database);
    }

    return Result;
}

class UAlchemyPlacableDatabaseSubset* UAlchemyDatabaseManager::GetDatabasesByAnyTags(const TArray<FName>& AnyOfTags) const
{
    UAlchemyPlacableDatabaseSubset* Result = NewObject<UAlchemyPlacableDatabaseSubset>();

    // Filter databases by tags
    for (UAlchemyPlacableDatabase* Database : PlacableDatabases)
    {
        if (!Database)
        {
            continue;
        }

        for (const FName& Tag : AnyOfTags)
        {
            if (Database->Tags.Contains(Tag))
            {
                Result->AddDatabase(Database);
                break;
            }
        }
    }

    return Result;
}

class UAlchemyPlacableDatabaseSubset* UAlchemyDatabaseManager::GetDatabasesByTag(const FName& Tag) const
{
    UAlchemyPlacableDatabaseSubset* Result = NewObject<UAlchemyPlacableDatabaseSubset>();

    // Filter databases by tags
    for (UAlchemyPlacableDatabase* Database : PlacableDatabases)
    {
        if (!Database)
        {
            continue;
        }

        if (Database->Tags.Contains(Tag))
        {
            Result->AddDatabase(Database);
            break;
        }
    }

    return Result;
}

void UAlchemyDatabaseManager::AddGeneratorDatabase(UAlchemyGeneratorDatabase* Database)
{
    if (Database)
    {
        GeneratorDatabases.Add(Database);
    }
}


TArray<FProceduralGeneratorInfo> UAlchemyDatabaseManager::GetGeneratorsByRequiredTags(const TArray<FName>& RequiredTags) const
{
    TArray<FProceduralGeneratorInfo> Result;

    // Search each database in the subset
    for (const UAlchemyGeneratorDatabase* Database : GeneratorDatabases)
    {
        if (Database)
        {
            Result.Append(Database->GetGeneratorsByRequiredTags(RequiredTags));
        }
    }

    return Result;
}

TArray<FProceduralGeneratorInfo> UAlchemyDatabaseManager::GetGeneratorsByAnyTags(const TArray<FName>& AnyOfTags) const
{
    TArray<FProceduralGeneratorInfo> Result;

    // Search each database in the subset
    for (const UAlchemyGeneratorDatabase* Database : GeneratorDatabases)
    {
        if (Database)
        {
            Result.Append(Database->GetGeneratorsByAnyTags(AnyOfTags));
        }
    }

    return Result;
}

TArray<FProceduralGeneratorInfo> UAlchemyDatabaseManager::GetGeneratorsByTag(const FName& Tag) const
{
    TArray<FProceduralGeneratorInfo> Result;

    // Search each database in the subset
    for (const UAlchemyGeneratorDatabase* Database : GeneratorDatabases)
    {
        if (Database)
        {
            Result.Append(Database->GetGeneratorsByTag(Tag));
        }
    }

    return Result;
}
