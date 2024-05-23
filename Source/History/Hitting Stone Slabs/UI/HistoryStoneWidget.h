// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HistoryStoneWidget.generated.h"

/**
 * 
 */
UCLASS()
class HISTORY_API UHistoryStoneWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void UpdateCount(int32 Num);

protected:
	virtual void NativeConstruct() override;
	
private:
	TObjectPtr<class UTextBlock> RemainingStoneCount;
};
