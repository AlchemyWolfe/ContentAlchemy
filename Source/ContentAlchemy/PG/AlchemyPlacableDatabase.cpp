// Copyright Alchemy Wolfe.  All Rights Reserved.

#include "AlchemyPlacableDatabase.h"

TArray<FAlchemyPlacableData> UAlchemyPlacableDatabase::GetPlacablesByTags(const TArray<FName>& RequiredTags, const TArray<FName>& OptionalTags) const
{
    TArray<FAlchemyPlacableData> FilteredPlacables;

    for (const FAlchemyPlacableData& Placable : Placables)
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

        // Check optional tags
        bool bMatchesOptional = OptionalTags.Num() == 0;
        if (!bMatchesOptional)
        {
            for (const FName& Tag : OptionalTags)
            {
                if (Placable.Tags.Contains(Tag))
                {
                    bMatchesOptional = true;
                    break;
                }
            }
        }

        if (bMatchesOptional)
        {
            FilteredPlacables.Add(Placable);
        }
    }

    return FilteredPlacables;
}
