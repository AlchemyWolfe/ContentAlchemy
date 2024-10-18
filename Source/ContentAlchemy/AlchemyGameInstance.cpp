// Copyright Alchemy Wolfe.  All Rights Reserved.

#include "AlchemyGameInstance.h"

void UAlchemyGameInstance::Init()
{
    Super::Init();
    if (!AlchemyDatabaseManager)
    {
        UE_LOG(LogTemp, Warning, TEXT("No AlchemyDatabaseManager found.  Has the correct BP been set in ProjectSettings->Maps & Modes->GameInstanceClass?"));
        AlchemyDatabaseManager = NewObject<UAlchemyDatabaseManager>(this, UAlchemyDatabaseManager::StaticClass());
    }
}
