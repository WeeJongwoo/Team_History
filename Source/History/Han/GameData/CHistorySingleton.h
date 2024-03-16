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
	
private:
	UCHistorySingleton();

public:
	static UCHistorySingleton& Get();

	FORCEINLINE uint16 GetCurrentInteractionNum() { return HeritageInteractionNum; }
	FORCEINLINE void IncreaseInteractionNum() { HeritageInteractionNum++; }
	FORCEINLINE void ResetInteractionNum() { HeritageInteractionNum = 0; }
	FORCEINLINE uint16 GetInteractionBaseline() { return HeritageInteractionBaseline; }

private:
	uint16 HeritageInteractionNum;
	uint16 HeritageInteractionBaseline;
};
