// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "CHistoryLevelScriptActor.generated.h"

UCLASS()
class HISTORY_API ACHistoryLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	FORCEINLINE void IncreaseInteractionNum() { HeritageInteractionCurrentCount++; }
	FORCEINLINE void ResetInteractionNum() { HeritageInteractionCurrentCount = 0; }
	FORCEINLINE bool IsPassable() { return (HeritageInteractionCurrentCount >= HeritageInteractionBaseline); }

protected:
	//각 레벨에 이미 도달했음을 check하는 bool변수, Singleton 디자인으로 접근해야 할 듯.
	//bool bTravelAlready;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Heritage)
	int32 HeritageInteractionBaseline;
	int32 HeritageInteractionCurrentCount;
};
