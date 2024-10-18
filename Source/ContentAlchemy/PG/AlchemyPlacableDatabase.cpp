// Copyright Alchemy Wolfe.  All Rights Reserved.

#include "AlchemyPlacableDatabase.h"

TArray<FAlchemyPlacable*> UAlchemyPlacableDatabase::GetPlacablesByRequiredTags(const TArray<FName>& RequiredTags) const
{
    TArray<FAlchemyPlacable*> Result;

    for (const FAlchemyPlacable& Placable : Placables)
    {
        // Check required tags
        bool bMatchesRequired = true;
        for (const FName& Tag : RequiredTags)
        {
            if (!Placable.Tags.Contains(Tag))
            {
                bMatchesRequired = false;
                break;
            }
        }

        if (!bMatchesRequired)
            continue;

        Result.Add(const_cast<FAlchemyPlacable*>(&Placable));
    }

    return Result;
}

UFUNCTION(BlueprintCallable, Category = "ContentAlchemy")
TArray<FAlchemyPlacable*> UAlchemyPlacableDatabase::GetPlacablesByAnyTags(const TArray<FName>& AnyOfTags) const
{
    TArray<FAlchemyPlacable*> Result;

    for (const FAlchemyPlacable& Placable : Placables)
    {
        for (const FName& Tag : AnyOfTags)
        {
            if (Placable.Tags.Contains(Tag))
            {
                Result.Add(const_cast<FAlchemyPlacable*>(&Placable));
                break;
            }
        }
    }

    return Result;
}

UFUNCTION(BlueprintCallable, Category = "ContentAlchemy")
TArray<FAlchemyPlacable*> UAlchemyPlacableDatabase::GetPlacablesByTag(const FName& Tag) const
{
    TArray<FAlchemyPlacable*> Result;

    for (const FAlchemyPlacable& Placable : Placables)
    {
        if (Placable.Tags.Contains(Tag))
        {
            Result.Add(const_cast<FAlchemyPlacable*>(&Placable));
            break;
        }
    }

    return Result;
}
