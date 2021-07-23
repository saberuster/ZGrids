// Fill out your copyright notice in the Description page of Project Settings.


#include "ZGridsStateComponent.h"

UZGridsStateComponent::UZGridsStateComponent(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
}

void UZGridsStateComponent::AddGridLayout(const FZGridLayoutHandle& LayoutHandle)
{
	GridContainerMap.Add(LayoutHandle, FZGridContainer{});
}

bool UZGridsStateComponent::ContainsGridLayout(const FZGridLayoutHandle& LayoutHandle) const
{
	return GridContainerMap.Contains(LayoutHandle);
}
