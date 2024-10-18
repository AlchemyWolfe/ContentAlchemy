// Copyright Alchemy Wolfe.  All Rights Reserved.

#include "AlchemyGenerator.h"
#include "Engine/World.h"
#include "ProceduralGeneratorInterface.h"
#include "Kismet/GameplayStatics.h"

AAlchemyGenerator::AAlchemyGenerator()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AAlchemyGenerator::BeginPlay()
{
    Super::BeginPlay();

    if (GenerateOwnSeed)
    {
        Seed = FMath::Rand32();
        Generate(Seed);
    }

}

void AAlchemyGenerator::Generate(int32 seed)
{
    Seed = seed;

    UAlchemyGameInstance* GameInstance = Cast<UAlchemyGameInstance>(GetWorld()->GetGameInstance());
    if (!GameInstance)
    {
        UE_LOG(LogTemp, Warning, TEXT("No AlchemyGameInstance found.  Perhaps GameInstance defaults to something else."));
        return;
    }

    AlchemyDatabaseManager = GameInstance->AlchemyDatabaseManager;
    PlacableDatabaseSubset = AlchemyDatabaseManager->GetDatabasesByRequiredTags(PlacableTags);
    Generator = GetRandomGenerator();
    if (!Generator)
    {
        UE_LOG(LogTemp, Warning, TEXT("No Generator found."));
        return;
    }
    Generator->SetSeed(Seed);
    Generator->SetOrigin(GetActorLocation() - FVector(100,100,0));  // For now, I know the floor tiles are 200x200x20.
    Generator->SetExtents(FVector(1000, 1000, 200));
    Generator->SetPlacableDatabaseSubset(PlacableDatabaseSubset);
    Generator->Generate();
}

IProceduralGeneratorInterface* AAlchemyGenerator::GetRandomGenerator()
{
    TArray<FProceduralGeneratorInfo> GeneratorInfos = AlchemyDatabaseManager->GetGeneratorsByRequiredTags(GeneratorTags);

    // Check if any generators are available
    if (GeneratorInfos.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("No generators found with the required tags."));
        return nullptr;
    }

    int32 RandomIndex = Seed % GeneratorInfos.Num();
    const FProceduralGeneratorInfo& ChosenGeneratorInfo = GeneratorInfos[RandomIndex];

    // Ensure the chosen generator class implements the interface
    if (!ChosenGeneratorInfo.GeneratorClass->ImplementsInterface(UProceduralGeneratorInterface::StaticClass()))
    {
        UE_LOG(LogTemp, Warning, TEXT("Chosen generator class does not implement the ProceduralGeneratorInterface."));
        return nullptr;
    }

    // Instantiate the generator class
    UObject* GeneratorObject = NewObject<UObject>(this, ChosenGeneratorInfo.GeneratorClass);
    if (!GeneratorObject)
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to create instance of generator class."));
        return nullptr;
    }

    // Return the generator interface
    return Cast<IProceduralGeneratorInterface>(GeneratorObject);
}

void AAlchemyGenerator::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Call the procedural generation interface
}
