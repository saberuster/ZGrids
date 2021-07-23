// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ZGrid.h"
#include "ZGridsTypes.h"
#include "Subsystems/WorldSubsystem.h"
#include "ZGridsSubsystem.generated.h"

struct FRequestCreateGridObjectParams 
{
	FRequestCreateGridObjectParams(){};
};

/**
 * 
 */
UCLASS()
class ZGRIDS_API UZGridsSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
protected:
	virtual bool DoesSupportWorldType(EWorldType::Type WorldType) const override;

public:

	static UZGridsSubsystem* GetGridsSubsystem(const UWorld* InWorld);

	UFUNCTION(BlueprintCallable, Category="ZGridsSubsystem", meta=(DisplayName="CreateGrids"))
	bool BP_CreateGridLayout(FZGridLayoutHandle& OutGridLayoutHandle);
	
	FZGridLayoutHandle CreateGridLayout();
	
	UFUNCTION(BlueprintCallable, Category="ZGridsSubsystem", meta=(DisplayName="CreateDefaultGrid"))
	UZGrid* BP_CreateDefaultGrid(const FZGridLayoutHandle& GridLayoutHandle,const FZGridCoordinate& Coordinate);
	
	UZGrid* CreateDefaultGrid(const FZGridLayoutHandle& GridLayoutHandle,const FZGridCoordinate& Coordinate);

	UFUNCTION(BlueprintCallable, Category="ZGridsSubsystem", meta=(DisplayName="FindGrid"))
	UZGrid* BP_FindGrid(const FZGridLayoutHandle& GridLayoutHandle,const FZGridCoordinate& Coordinate);
	
	UZGrid* FindGrid(const FZGridLayoutHandle& GridLayoutHandle,const FZGridCoordinate& Coordinate);

	bool ResetGrid(const FZGridLayoutHandle& GridLayoutHandle,const FZGridCoordinate& Coordinate, UZGrid* InGrid);

protected:

	TSubclassOf<UZGrid> GetDefaultGridClass() const;
	
	UZGrid* CreateGridObjectInternal(TSubclassOf<UZGrid> GridClass, const FZGridLayoutHandle& GridsHandle,const FZGridCoordinate& Coordinate,const FRequestCreateGridObjectParams& Params = FRequestCreateGridObjectParams{});

	
};
