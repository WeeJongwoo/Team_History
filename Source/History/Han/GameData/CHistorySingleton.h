// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CHistorySingleton.generated.h"

/**
 * 
 */
UCLASS()
class HISTORY_API UCHistorySingleton : public UObject
{
	GENERATED_BODY()

public:
	static UCHistorySingleton& Get();

	void AddTraveledLevel(FName TraveledLevelName);

private:
	TArray<FName> TraveledLevels;

};
