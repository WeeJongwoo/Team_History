#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CHeritageDataRow.generated.h"

USTRUCT(BlueprintType)
struct FCHeritageDataRow : public FTableRowBase
{
	GENERATED_BODY()

	public:
	FCHeritageDataRow() : InteractionDistance(0.0f), HeritageName(TEXT("")), HeritageDescription(TEXT("")) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HeritageData)
	float InteractionDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HeritageData)
	FString HeritageName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HeritageData)
	FString HeritageDescription;
};