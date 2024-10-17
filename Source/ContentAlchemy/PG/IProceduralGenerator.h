// IProceduralGenerator.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ProceduralGeneratorInterface.generated.h"

UINTERFACE(MinimalAPI)
class UProceduralGeneratorInterface : public UInterface
{
    GENERATED_BODY()
};

class YOURPROJECT_API IProceduralGeneratorInterface
{
    GENERATED_BODY()

public:
    // Initialize the generator if needed
    virtual void Initialize(UWorld* World, const FAlchemyPlacableData& PlacableData) = 0;

    // Execute the generation logic
    virtual void Generate() = 0;
};
