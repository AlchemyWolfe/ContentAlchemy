// Copyright Alchemy Wolfe.  All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class CONTENTALCHEMY_API AlchemyUtils
{
public:
    template<typename T>
    static T GetRandomElement(const TArray<T>& Array, FRandomStream& RandomStream)
    {
        if (Array.Num() == 0)
        {
            return T(); // Return default value if array is empty
        }

        return Array[RandomStream.RandRange(0, Array.Num() - 1)];
    }

    template<typename T>
    static T* GetRandomElementPointer(const TArray<T>& Array, FRandomStream& RandomStream)
    {
        if (Array.Num() == 0)
        {
            return nullptr;
        }

        return &Array[RandomStream.RandRange(0, Array.Num() - 1)];
    }
};
