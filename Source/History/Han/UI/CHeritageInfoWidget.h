// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CHeritageInfoWidget.generated.h"

/**
 *
 */
UCLASS()
class HISTORY_API UCHeritageInfoWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	FORCEINLINE void SetOwningActor(AActor* NewOwner) { OwningActor = NewOwner; }
	//	//void SetTitle(FText NewTitle);
	//	//void SetDesc(FText NewDesc);
	//	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Actor)
	TObjectPtr<AActor> OwningActor;
	//	TObjectPtr<class UTextBlock> TitleTextBlock;
	//	TObjectPtr<class UTextBlock> DescTextBlock;
};
