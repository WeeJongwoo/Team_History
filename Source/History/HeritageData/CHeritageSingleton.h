// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CHeritageDataRow.h"
#include "CHeritageSingleton.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogCHeritageSingleton, Error, All);

/**
 * 
 */
UCLASS()
class HISTORY_API UCHeritageSingleton : public UObject
{
	GENERATED_BODY()
	
public:
	UCHeritageSingleton();
	static UCHeritageSingleton& Get();

public:
	FCHeritageDataRow* GetHeritageData(FName InHeritageStaticMeshName);
	
private:
	UDataTable* HeritageDataTable;
};
