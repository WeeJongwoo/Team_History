// Fill out your copyright notice in the Description page of Project Settings.


#include "HeritageData/CHeritageSingleton.h"

DEFINE_LOG_CATEGORY(LogCHeritageSingleton);

UCHeritageSingleton::UCHeritageSingleton()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> HeritageDataTableRef(TEXT("/Script/Engine.DataTable'/Game/HanJinHo/HeritageData/CHeritageDataTable.CHeritageDataTable'"));
	if (HeritageDataTableRef.Object != nullptr)
	{
		HeritageDataTable = HeritageDataTableRef.Object;
	}
}

UCHeritageSingleton& UCHeritageSingleton::Get()
{
	UCHeritageSingleton* Singleton = CastChecked<UCHeritageSingleton>(GEngine->GameSingleton);
	if (Singleton)
	{
		return *Singleton;
	}

	UE_LOG(LogCHeritageSingleton, Error, TEXT("Invalid Game Singleton"));
	return *NewObject<UCHeritageSingleton>();
}

FCHeritageDataRow* UCHeritageSingleton::GetHeritageData(FName InHeritageStaticMeshName)
{
	FCHeritageDataRow* FindResult = HeritageDataTable->FindRow<FCHeritageDataRow>(InHeritageStaticMeshName, TEXT(""));
	if (FindResult != nullptr)
	{
		return FindResult;
	}
	
	UE_LOG(LogTemp, Warning, TEXT("Not Found Data"));
	return HeritageDataTable->FindRow<FCHeritageDataRow>(TEXT("FailedData"), TEXT(""));
}
