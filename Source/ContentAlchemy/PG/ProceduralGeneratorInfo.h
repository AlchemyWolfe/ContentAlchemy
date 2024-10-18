// Copyright Alchemy Wolfe.  All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralGeneratorInterface.h"
#include "ProceduralGeneratorInfo.generated.h"

USTRUCT(BlueprintType)
struct FProceduralGeneratorInfo
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generator")
    TSubclassOf<UObject> GeneratorClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generator")
    TArray<FName> Tags;
};
