// Copyright Alchemy Wolfe.  All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PG/AlchemyDatabaseManager.h"
#include "AlchemyGameInstance.generated.h"

UCLASS()
class CONTENTALCHEMY_API UAlchemyGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ContentAlchemy")
    UAlchemyDatabaseManager* AlchemyDatabaseManager;

    virtual void Init() override;
};
