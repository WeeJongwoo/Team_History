// Fill out your copyright notice in the Description page of Project Settings.


#include "Han/GameData/CHistorySingleton.h"

UCHistorySingleton& UCHistorySingleton::Get()
{
	UCHistorySingleton* Singleton = CastChecked<UCHistorySingleton>(GEngine->GameSingleton);
	if (Singleton)
	{
		return *Singleton;
	}

	return *NewObject<UCHistorySingleton>();
}

void UCHistorySingleton::AddTraveledLevel(FName TraveledLevelName)
{
	TraveledLevels.AddUnique(TraveledLevelName);
}
