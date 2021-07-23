// Fill out your copyright notice in the Description page of Project Settings.


#include "ZGridsSubsystem.h"

#include "ZGridsLibrary.h"
#include "ZGridsSettings.h"
#include "ZGridsStateComponent.h"
#include "GameFramework/GameStateBase.h"

void UZGridsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UZGridsSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

bool UZGridsSubsystem::DoesSupportWorldType(EWorldType::Type WorldType) const
{
	return WorldType == EWorldType::Game || WorldType == EWorldType::PIE;
}

UZGridsSubsystem* UZGridsSubsystem::GetGridsSubsystem(const UWorld* InWorld)
{
	checkf(InWorld != nullptr, TEXT(" InWorld should not be nullptr! ")); 
	return InWorld->GetSubsystem<UZGridsSubsystem>();
}

bool UZGridsSubsystem::BP_CreateGridLayout(FZGridLayoutHandle& OutGridsHandle)
{
	OutGridsHandle = CreateGridLayout();
	return OutGridsHandle.IsValid();
}

FZGridLayoutHandle UZGridsSubsystem::CreateGridLayout()
{
	auto GridsState = UZGridsLibrary::GetZGridsStateComponent(GetWorld());
	if (ensureMsgf(GridsState != nullptr, TEXT(" please add ZGridsStateComponent to GameState Actor")))
	{
		FZGridLayoutHandle NewGridLayoutHandle{};
		NewGridLayoutHandle.GenerateNewHandle();
		if (ensureMsgf(GridsState->ContainsGridLayout(NewGridLayoutHandle), TEXT("GridLayout has exist!")))
		{
			return FZGridLayoutHandle{};
		}

		GridsState->AddGridLayout(NewGridLayoutHandle);
		
		return NewGridLayoutHandle;
	}

	return FZGridLayoutHandle{};
}

UZGrid* UZGridsSubsystem::BP_CreateDefaultGrid(const FZGridLayoutHandle& GridLayoutHandle, const FZGridCoordinate& Coordinate)
{
	return CreateDefaultGrid(GridLayoutHandle, Coordinate);
}

UZGrid* UZGridsSubsystem::CreateDefaultGrid(const FZGridLayoutHandle& GridLayoutHandle, const FZGridCoordinate& Coordinate)
{
	if (ensureMsgf(GridLayoutHandle.IsValid() && Coordinate.IsValid(), TEXT(" GridsHandle or Coordinate is InValid! ")))
	{

		auto GridsState = UZGridsLibrary::GetZGridsStateComponent(GetWorld());
		auto GridContainer = GridsState->GridContainerMap.Find(GridLayoutHandle);
		if (GridContainer)
		{
			
			auto Grid = CreateGridObjectInternal(GetDefaultGridClass(), GridLayoutHandle, Coordinate);
			GridContainer->GridMap.Add(Coordinate, Grid);
			
			return Grid;
		}
			
	}

	return nullptr;
}
UZGrid* UZGridsSubsystem::BP_FindGrid(const FZGridLayoutHandle& GridsHandle, const FZGridCoordinate& Coordinate)
{
	return FindGrid(GridsHandle, Coordinate);
}

UZGrid* UZGridsSubsystem::FindGrid(const FZGridLayoutHandle& GridsHandle, const FZGridCoordinate& Coordinate)
{
	auto GridsState = UZGridsLibrary::GetZGridsStateComponent(GetWorld());
	auto GridContainer = GridsState->GridContainerMap.Find(GridsHandle);
	if (GridContainer)
	{
		return GridContainer->GridMap.Find(Coordinate)->Get();
	}

	return nullptr;
}

bool UZGridsSubsystem::ResetGrid(const FZGridLayoutHandle& GridsHandle, const FZGridCoordinate& Coordinate, UZGrid* InGrid)
{
	if (ensureMsgf(GridsHandle.IsValid() && Coordinate.IsValid() && InGrid != nullptr, TEXT(" GridsHandle or Coordinate is InValid! ")))
	{
		auto GridsState = UZGridsLibrary::GetZGridsStateComponent(GetWorld());
		auto GridContainer = GridsState->GridContainerMap.Find(GridsHandle);
		if (GridContainer)
		{
			auto Grid = NewObject<UZGrid>(this);
			GridContainer->GridMap.Add(Coordinate, Grid);
		}
			
	}

	return false;
}

TSubclassOf<UZGrid> UZGridsSubsystem::GetDefaultGridClass() const
{
	auto GridClassName = GetDefault<UZGridsSettings>()->DefaultGridClass;
	auto GridClass = GridClassName.TryLoadClass<UZGrid>();
	if (!GridClass)
	{
		GridClass = UZGrid::StaticClass();
	}

	return GridClass;
}	

		

UZGrid* UZGridsSubsystem::CreateGridObjectInternal(TSubclassOf<UZGrid> GridClass, const FZGridLayoutHandle& GridsHandle,const FZGridCoordinate& Coordinate, const FRequestCreateGridObjectParams& Params)
{
	auto ReturnGrid = NewObject<UZGrid>(this, GridClass);
	ReturnGrid->InitGrid(GridsHandle, Coordinate);
	return ReturnGrid;
}
