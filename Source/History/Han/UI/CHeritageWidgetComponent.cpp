// Fill out your copyright notice in the Description page of Project Settings.


#include "Han/UI/CHeritageWidgetComponent.h"
#include "Han/UI/CHeritageInfoWidget.h"

void UCHeritageWidgetComponent::InitWidget()
{
	Super::InitWidget();

	UCHeritageInfoWidget* HeritageInfoWidget = Cast<UCHeritageInfoWidget>(GetWidget());
	if (HeritageInfoWidget)
	{
		HeritageInfoWidget->SetOwningActor(GetOwner());
	}
}

