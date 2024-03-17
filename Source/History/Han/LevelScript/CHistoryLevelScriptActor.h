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
	//�� ������ �̹� ���������� check�ϴ� bool����, Singleton ���������� �����ؾ� �� ��.
	//bool bTravelAlready;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Heritage)
	int32 HeritageInteractionBaseline;
	int32 HeritageInteractionCurrentCount;
};
