// Fill out your copyright notice in the Description page of Project Settings.


#include "Hitting Stone Slabs/UI/HistoryStoneHUD.h"
#include "HistoryStoneWidget.h"
#include "HistoryStoneClearWidget.h"

UHistoryStoneHUD::UHistoryStoneHUD(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{

}

void UHistoryStoneHUD::NativeConstruct()
{
	Super::NativeConstruct();

	StoneCount = Cast<UHistoryStoneWidget>(GetWidgetFromName(TEXT("StoneCountWidget")));
	ensure(StoneCount);

	ClearWidget = Cast<UHistoryStoneClearWidget>(GetWidgetFromName(TEXT("StoneClearWidget")));
	ensure(ClearWidget);

	StoneCount->SetVisibility(ESlateVisibility::Visible);
	ClearWidget->SetVisibility(ESlateVisibility::Collapsed);

}

void UHistoryStoneHUD::UpdateCount(int32 CurrentNum)
{
	StoneCount->UpdateCount(CurrentNum);
}

void UHistoryStoneHUD::IsClear()
{
	StoneCount->SetVisibility(ESlateVisibility::Collapsed);
	ClearWidget->SetVisibility(ESlateVisibility::Visible);
}
