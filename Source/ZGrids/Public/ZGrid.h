// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ZGridsTypes.h"
#include "UObject/Object.h"
#include "ZGrid.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class ZGRIDS_API UZGrid : public UObject
{
	GENERATED_BODY()

public:

	UZGrid(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadOnly, Category="ZGrid")
	FZGridLayoutHandle GridLayoutHandle;

	UPROPERTY(BlueprintReadOnly, Category="ZGrid")
	FZGridCoordinate GridCoordinate;

	virtual void InitGrid(const FZGridLayoutHandle& InGridsHandle,const FZGridCoordinate& InCoordinate);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="InitGrid"))
	void BP_InitGrid();

	UFUNCTION(BlueprintCallable)
	AActor* SpawnActor(TSubclassOf<AActor> ActorClass,const FTransform& Transform);

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	void GetNeighbors(TArray<UZGrid*>& NeighborArray);
	virtual void GetNeighbors_Implementation(TArray<UZGrid*>& NeighborArray);

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	void GetAvatarTransform(FTransform& Transform);
	virtual void GetAvatarTransform_Implementation(FTransform& Transform);
	
};
