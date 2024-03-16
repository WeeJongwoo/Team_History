// Fill out your copyright notice in the Description page of Project Settings.


#include "Han/GameData/CHistorySingleton.h"

UCHistorySingleton::UCHistorySingleton()
{
	ResetInteractionNum();
	HeritageInteractionBaseline = 2;
}

UCHistorySingleton& UCHistorySingleton::Get()
{
	UCHistorySingleton* Singleton = CastChecked<UCHistorySingleton>(GEngine->GameSingleton);
	if (Singleton)
	{
		return *Singleton;
	}

	return *NewObject<UCHistorySingleton>();
}
