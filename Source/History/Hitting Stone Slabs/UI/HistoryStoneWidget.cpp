// Fill out your copyright notice in the Description page of Project Settings.


#include "Hitting Stone Slabs/UI/HistoryStoneWidget.h"
#include "Components/TextBlock.h"



void UHistoryStoneWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UTextBlock* CountTextBox = Cast<UTextBlock>(GetWidgetFromName(TEXT("TxtRemainingStoneCount")));
	if (CountTextBox)
	{
		RemainingStoneCount = CountTextBox;
	}
}

void UHistoryStoneWidget::UpdateCount(int32 Num)
{
	RemainingStoneCount->SetText(FText::FromString(FString::FromInt(Num)));
}