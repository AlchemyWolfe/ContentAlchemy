// Copyright Alchemy Wolfe.  All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AlchemyGeneratorDatabase.h"
#include "AlchemyPlacableDatabase.h"
#include "../AlchemyGameInstance.h"
#include "AlchemyGenerator.generated.h"

UCLASS()
class CONTENTALCHEMY_API AAlchemyGenerator : public AActor
{
    GENERATED_BODY()

public:
    AAlchemyGenerator();

    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ContentAlchemy")
    bool GenerateOwnSeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ContentAlchemy")
    TArray<FName> PlacableTags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ContentAlchemy")
    TArray<FName> GeneratorTags;

protected:
    virtual void BeginPlay() override;

private:
    void Generate(int32 seed);
    IProceduralGeneratorInterface* GetRandomGenerator();

    UAlchemyDatabaseManager* AlchemyDatabaseManager;
    class UAlchemyPlacableDatabaseSubset* PlacableDatabaseSubset;
    IProceduralGeneratorInterface* Generator;
    int32 Seed;
    bool SeedGenerated;
};
