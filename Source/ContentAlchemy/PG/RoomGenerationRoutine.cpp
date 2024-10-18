// Copyright Alchemy Wolfe.  All Rights Reserved.

#include "RoomGenerationRoutine.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "AlchemyUtils.h"

/*
void URoomGenerationRoutine::Generate(FAlchemyPlacableSet& PlacableSet, const FVector& Dimensions, const TArray<FVector>& DoorLocations)
{
    UWorld* World = GetWorld();
    if (!World) return;

    const float TileSize = 100.0f;  // Example grid tile size

    // Step 1: Generate the floor
    for (int32 X = 0; X < Dimensions.X; X++)
    {
        for (int32 Y = 0; Y < Dimensions.Y; Y++)
        {
            FVector Location = FVector(X * TileSize, Y * TileSize, 0);
            FAlchemyPlacable FloorTile = PlacableSet.PlacedItems[0]; // Assume first item is the floor

            // Spawn the floor tile at the grid location
            World->SpawnActor<AActor>(FloorTile.ActorClass, Location, FRotator::ZeroRotator);
        }
    }

    // Step 2: Generate the walls
    for (int32 X = 0; X < Dimensions.X; X++)
    {
        // Left and right walls
        FVector LeftWallLocation = FVector(X * TileSize, 0, TileSize);
        FVector RightWallLocation = FVector(X * TileSize, Dimensions.Y * TileSize, TileSize);

        FAlchemyPlacable WallTile = PlacableSet.PlacedItems[1]; // Assume second item is the wall

        World->SpawnActor<AActor>(WallTile.ActorClass, LeftWallLocation, FRotator::ZeroRotator);
        World->SpawnActor<AActor>(WallTile.ActorClass, RightWallLocation, FRotator::ZeroRotator);
    }

    for (int32 Y = 0; Y < Dimensions.Y; Y++)
    {
        // Top and bottom walls
        FVector TopWallLocation = FVector(0, Y * TileSize, TileSize);
        FVector BottomWallLocation = FVector(Dimensions.X * TileSize, Y * TileSize, TileSize);

        World->SpawnActor<AActor>(WallTile.ActorClass, TopWallLocation, FRotator::ZeroRotator);
        World->SpawnActor<AActor>(WallTile.ActorClass, BottomWallLocation, FRotator::ZeroRotator);
    }

    // Step 3: Place doors based on DoorLocations
    FAlchemyPlacable DoorTile = PlacableSet.PlacedItems[2]; // Assume third item is the door
    for (const FVector& DoorLocation : DoorLocations)
    {
        World->SpawnActor<AActor>(DoorTile.ActorClass, DoorLocation, FRotator::ZeroRotator);
    }

    // Add additional room generation steps as needed (e.g., decorations, objects, etc.)
}
*/

URoomGenerationRoutine::URoomGenerationRoutine()
{
    SeedIsSet = false;
}

void URoomGenerationRoutine::Generate()
{
    GenerateMissingPlacables();
    if (Floors.Num() == 0)
    {
        // Floors is the critical one.  Aborting.  Error already sent in GenerateMissingPlacables.
        return;
    }

    FAlchemyPlacable* FirstFloorTile = Floors[0];
    AActor* TempTile = GetWorld()->SpawnActor<AActor>(FirstFloorTile->PlacableClass, FVector::ZeroVector, FRotator::ZeroRotator);
    if (!TempTile)
    {
        // Exit if we failed to spawn the tile
        return;
    }
    FVector FloorTileSize = TempTile->GetActorScale() * TempTile->GetComponentsBoundingBox().GetSize();
    // Clean up the temporary tile, we were only using it to get the dimensions.
    TempTile->Destroy();

    // Generate the floors.
    FVector StartPosition = Origin + MinExtents;
    FVector EndPosition = Origin + MaxExtents - FloorTileSize;
    FVector TilePosition = StartPosition;
    for (TilePosition.X = StartPosition.X; TilePosition.X <= EndPosition.X; TilePosition.X += FloorTileSize.X)
    {
        for (TilePosition.Y = StartPosition.Y; TilePosition.Y <= EndPosition.Y; TilePosition.Y += FloorTileSize.Y)
        {
            // Spawn the floor tile actor
            FAlchemyPlacable* FloorTile = AlchemyUtils::GetRandomElement(Floors, RandomStream);
            AActor* FloorTileActor = GetWorld()->SpawnActor<AActor>(FloorTile->PlacableClass, TilePosition, FRotator::ZeroRotator);
        }
    }
    FVector ActualEndPosition = TilePosition;

    FAlchemyPlacable* FirstWallTile = Walls[0];
    TempTile = GetWorld()->SpawnActor<AActor>(FirstWallTile->PlacableClass, FVector::ZeroVector, FRotator::ZeroRotator);
    if (!TempTile)
    {
        // Exit if we failed to spawn the tile
        return;
    }
    FVector WallTileSize = TempTile->GetActorScale() * TempTile->GetComponentsBoundingBox().GetSize();
    // Clean up the temporary tile, we were only using it to get the dimensions.
    TempTile->Destroy();

    // Generate walls all around.
    TilePosition.Y = StartPosition.Y;
    FVector FarTilePosition = TilePosition;
    FarTilePosition.Y = ActualEndPosition.Y;
    FRotator NearWallRotator = FRotator::ZeroRotator;
    FRotator FarWallRotator = FRotator(0, 180, 0);
    for (TilePosition.X = StartPosition.X; TilePosition.X <= EndPosition.X; TilePosition.X += FloorTileSize.X)
    {
        // Spawn the near wall tile actor
        FAlchemyPlacable* WallTile = AlchemyUtils::GetRandomElement(Walls, RandomStream);
        AActor* WallTileActor = GetWorld()->SpawnActor<AActor>(WallTile->PlacableClass, TilePosition, NearWallRotator);

        // Spawn the far wall tile actor
        FarTilePosition.X = TilePosition.X + FloorTileSize.X;
        WallTile = AlchemyUtils::GetRandomElement(Walls, RandomStream);
        WallTileActor = GetWorld()->SpawnActor<AActor>(WallTile->PlacableClass, FarTilePosition, FarWallRotator);
    }

    // And again for the other two sides.
    TilePosition.X = StartPosition.X;
    FarTilePosition = TilePosition;
    FarTilePosition.X = ActualEndPosition.X;
    NearWallRotator = FRotator(0, 90, 0);
    FarWallRotator = FRotator(0, 270, 0);
    for (TilePosition.Y = StartPosition.Y; TilePosition.Y <= EndPosition.Y; TilePosition.Y += FloorTileSize.Y)
    {
        // Spawn the near wall tile actor
        FAlchemyPlacable* WallTile = AlchemyUtils::GetRandomElement(Walls, RandomStream);
        AActor* WallTileActor = GetWorld()->SpawnActor<AActor>(WallTile->PlacableClass, TilePosition, NearWallRotator);

        // Spawn the far wall tile actor
        FarTilePosition.Y = TilePosition.Y + FloorTileSize.Y;
        WallTile = AlchemyUtils::GetRandomElement(Walls, RandomStream);
        WallTileActor = GetWorld()->SpawnActor<AActor>(WallTile->PlacableClass, FarTilePosition, FarWallRotator);
    }

}

void URoomGenerationRoutine::SetSeed(int32 seed)
{
    RandomStream.Initialize(seed);
    SeedIsSet = true;
}

void URoomGenerationRoutine::SetOrigin(const FVector& origin)
{
    Origin = origin;
}

void URoomGenerationRoutine::SetExtents(const FVector& max, const FVector& min)
{
    MinExtents = min;
    MaxExtents = max;
}

void URoomGenerationRoutine::SetPlacableDatabaseSubset(UAlchemyPlacableDatabaseSubset* placableDatabaseSubset)
{
    PlacableDatabaseSubset = placableDatabaseSubset;
}

void URoomGenerationRoutine::GenerateMissingPlacables()
{
    if (!SeedIsSet)
    {
        SetSeed(FMath::Rand());
    }
    if (!PlacableDatabaseSubset)
    {
        UE_LOG(LogTemp, Warning, TEXT("URoomGenerationRoutine::GenerateMissingPlacables : No PlacableDatabaseSubset found.  Can't generate a room without a database."));
        return;
    }
    if (Floors.Num() == 0)
    {
        Floors = PlacableDatabaseSubset->GetPlacablesByTag(FName("Floor"));
        if (Floors.Num() == 0)
        {
            UE_LOG(LogTemp, Warning, TEXT("URoomGenerationRoutine::GenerateMissingPlacables : No PlacableDatabaseSubset found.  Can't generate a room without floors."));
            return;
        }
    }
    if (Walls.Num() == 0)
    {
        Walls = PlacableDatabaseSubset->GetPlacablesByTag(FName("Wall"));
    }
    if (Doorways.Num() == 0)
    {
        Doorways = PlacableDatabaseSubset->GetPlacablesByTag(FName("Doorway"));
    }
}

void URoomGenerationRoutine::SetBasePlacables(TArray<FAlchemyPlacable*> floors, TArray<FAlchemyPlacable*> walls, TArray<FAlchemyPlacable*> doorways)
{
    Floors = floors;
    Walls = walls;
    Doorways = doorways;
}
