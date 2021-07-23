// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ZGridsTypes.h"
#include "Components/GameStateComponent.h"
#include "ZGridsStateComponent.generated.h"

class UZGridsSubsystem;
class UZGrid;

USTRUCT(BlueprintType)
struct FZGridContainer
{
	GENERATED_BODY()

	FZGridContainer(){}

	TMap<FZGridCoordinate,TObjectPtr<UZGrid>> GridMap;
	
};
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, Category = "ZGrids", meta = (BlueprintSpawnableComponent), HideCategories=(SOCKETS, COLLISION))
class ZGRIDS_API UZGridsStateComponent : public UGameStateComponent
{
	GENERATED_BODY()

public:

	UZGridsStateComponent(const FObjectInitializer& ObjectInitializer);

protected:

	UPROPERTY()
	TMap<FZGridLayoutHandle, FZGridContainer> GridContainerMap;

	void AddGridLayout(const FZGridLayoutHandle& LayoutHandle);

	bool ContainsGridLayout(const FZGridLayoutHandle& LayoutHandle) const;

	friend UZGridsSubsystem;
};
