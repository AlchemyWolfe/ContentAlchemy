// Copyright Alchemy Wolfe.  All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AlchemyPlacableDatabaseSubset.h"
#include "ProceduralGeneratorInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UProceduralGeneratorInterface : public UInterface
{
    GENERATED_BODY()
};

/**
 * Interface class for procedural generation routines.
 */
class CONTENTALCHEMY_API IProceduralGeneratorInterface
{
    GENERATED_BODY()

public:
    // Generate function for procedural content
    virtual void Generate() = 0;

    // Sets the seed for random generation
    virtual void SetSeed(int32 seed) = 0;

    // Sets the origin point for the generation.  If not called, generation will start at (0,0,0).
    virtual void SetOrigin(const FVector& origin) = 0;

    // Sets the extents generation relative to the origin.
    // Think of it as the size of the area, not it's world position.
    // In most cases, generation should expand positively from the origin.
    virtual void SetExtents(const FVector& max, const FVector& min = FVector(0, 0, 0)) = 0;

    // Set the subset of databases the generation routine can use.
    virtual void SetPlacableDatabaseSubset(UAlchemyPlacableDatabaseSubset* placableDatabaseSubset) = 0;
};
