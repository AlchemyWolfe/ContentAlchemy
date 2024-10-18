// Copyright Alchemy Wolfe.  All Rights Reserved.

#include "AlchemyPlacableDatabaseSubset.h"

void UAlchemyPlacableDatabaseSubset::AddDatabase(UAlchemyPlacableDatabase* Database)
{
    if (Database)
    {
        FilteredDatabases.Add(Database);
    }
}

TArray<FAlchemyPlacable*> UAlchemyPlacableDatabaseSubset::GetPlacablesByRequiredTags(const TArray<FName>& RequiredTags) const
{
    TArray<FAlchemyPlacable*> Result;

    // Search each database in the subset
    for (const UAlchemyPlacableDatabase* Database : FilteredDatabases)
    {
        if (Database)
        {
            Result.Append(Database->GetPlacablesByRequiredTags(RequiredTags));
        }
    }

    return Result;
}

TArray<FAlchemyPlacable*> UAlchemyPlacableDatabaseSubset::GetPlacablesByAnyTags(const TArray<FName>& AnyOfTags) const
{
    TArray<FAlchemyPlacable*> Result;

    // Search each database in the subset
    for (const UAlchemyPlacableDatabase* Database : FilteredDatabases)
    {
        if (Database)
        {
            Result.Append(Database->GetPlacablesByAnyTags(AnyOfTags));
        }
    }

    return Result;
}

TArray<FAlchemyPlacable*> UAlchemyPlacableDatabaseSubset::GetPlacablesByTag(const FName& Tag) const
{
    TArray<FAlchemyPlacable*> Result;

    // Search each database in the subset
    for (const UAlchemyPlacableDatabase* Database : FilteredDatabases)
    {
        if (Database)
        {
            Result.Append(Database->GetPlacablesByTag(Tag));
        }
    }

    return Result;
}
