// Copyright Alchemy Wolfe.  All Rights Reserved.

#include "AlchemyGeneratorDatabase.h"

TArray<FProceduralGeneratorInfo> UAlchemyGeneratorDatabase::GetGeneratorsByRequiredTags(const TArray<FName>& RequiredTags) const
{
    TArray<FProceduralGeneratorInfo> Result;

    for (const FProceduralGeneratorInfo& Info : Generators)
    {
        // Check required tags
        bool bMatchesRequired = true;
        for (const FName& Tag : RequiredTags)
        {
            if (!Info.Tags.Contains(Tag))
            {
                bMatchesRequired = false;
                break;
            }
        }

        if (!bMatchesRequired)
            continue;

        Result.Add(Info);
    }
    return Result;
}

TArray<FProceduralGeneratorInfo> UAlchemyGeneratorDatabase::GetGeneratorsByAnyTags(const TArray<FName>& AnyOfTags) const
{
    TArray<FProceduralGeneratorInfo> Result;
    for (const FProceduralGeneratorInfo& Info : Generators)
    {
        for (const FName& Tag : AnyOfTags)
        {
            if (Info.Tags.Contains(Tag))
            {
                Result.Add(Info);
                break;
            }
        }
    }
    return Result;
}

TArray<FProceduralGeneratorInfo> UAlchemyGeneratorDatabase::GetGeneratorsByTag(const FName& Tag) const
{
    TArray<FProceduralGeneratorInfo> Result;
    for (const FProceduralGeneratorInfo& Info : Generators)
    {
        if (Info.Tags.Contains(Tag))
        {
            Result.Add(Info);
            break;
        }
    }
    return Result;
}
