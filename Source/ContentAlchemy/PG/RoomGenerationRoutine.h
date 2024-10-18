// Copyright Alchemy Wolfe.  All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProceduralGeneratorInterface.h"
#include "RoomGenerationRoutine.generated.h"

// Forward declaration of IProceduralGeneratorInterface
class IProceduralGeneratorInterface;

UCLASS(Blueprintable)
class CONTENTALCHEMY_API URoomGenerationRoutine : public UObject, public IProceduralGeneratorInterface
{
    GENERATED_BODY()

public:
    URoomGenerationRoutine();

    // Inherited via IProceduralGeneratorInterface
    void Generate() override;
    void SetSeed(int32 seed) override;
    void SetOrigin(const FVector& origin) override;
    void SetExtents(const FVector& max, const FVector& min) override;
    void SetPlacableDatabaseSubset(UAlchemyPlacableDatabaseSubset* placableDatabaseSubset) override;

    void GenerateMissingPlacables();
    void SetBasePlacables(TArray<FAlchemyPlacable*> floors, TArray<FAlchemyPlacable*> walls, TArray<FAlchemyPlacable*> doorways);

private:
    FRandomStream RandomStream;
    bool SeedIsSet;
    UAlchemyPlacableDatabaseSubset* PlacableDatabaseSubset;
    TArray<FAlchemyPlacable*> Floors;
    TArray<FAlchemyPlacable*> Walls;
    TArray<FAlchemyPlacable*> Doorways;
    FVector Origin;
    FVector MinExtents;
    FVector MaxExtents;
};
