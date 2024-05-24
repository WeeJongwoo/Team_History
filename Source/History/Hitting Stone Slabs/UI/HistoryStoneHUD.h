// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HistoryStoneHUD.generated.h"

/**
 *
 */
UCLASS()
class HISTORY_API UHistoryStoneHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UHistoryStoneHUD(const FObjectInitializer& ObjectInitializer);

	void UpdateCount(int32 CurrentNum);

	void IsClear();

protected:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY()
	TObjectPtr<class UHistoryStoneWidget> StoneCount;

	UPROPERTY()
	TObjectPtr<class UHistoryStoneClearWidget> ClearWidget;
};
