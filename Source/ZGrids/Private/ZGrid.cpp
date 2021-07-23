// Fill out your copyright notice in the Description page of Project Settings.


#include "ZGrid.h"

UZGrid::UZGrid(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
}

void UZGrid::InitGrid(const FZGridLayoutHandle& InGridsHandle, const FZGridCoordinate& InCoordinate)
{
	GridLayoutHandle = InGridsHandle;
	GridCoordinate = InCoordinate;

	BP_InitGrid();
}

AActor* UZGrid::SpawnActor(TSubclassOf<AActor> ActorClass, const FTransform& Transform)
{
	return GetWorld()->SpawnActor<AActor>(ActorClass, Transform);
}

void UZGrid::GetNeighbors_Implementation(TArray<UZGrid*>& NeighborArray)
{
}

void UZGrid::GetAvatarTransform_Implementation(FTransform& Transform)
{
}




