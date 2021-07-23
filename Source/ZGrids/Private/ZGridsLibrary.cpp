// Fill out your copyright notice in the Description page of Project Settings.


#include "ZGridsLibrary.h"

#include "GameFramework/GameStateBase.h"

UZGridsStateComponent* UZGridsLibrary::BP_GetZGridsStateComponent(const UObject* WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	return GetZGridsStateComponent(World);
}

UZGridsStateComponent* UZGridsLibrary::GetZGridsStateComponent(UWorld* InWorld)
{
	return InWorld != nullptr ? GetZGridsStateComponent(InWorld->GetGameState()) : nullptr;
}

UZGridsStateComponent* UZGridsLibrary::GetZGridsStateComponent(AGameStateBase* InGameState)
{
	return InGameState != nullptr ? InGameState->FindComponentByClass<UZGridsStateComponent>() : nullptr;
}

FZGridCoordinate UZGridsLibrary::MakeZGridCoordinate(int32 InX, int32 InY, int32 InZ)
{
	return FZGridCoordinate(InX, InY, InZ);
}

FZGridCoordinate UZGridsLibrary::MakeZGridCoordinateFromXY(int32 InX, int32 InY)
{
	return FZGridCoordinate(InX, InY);
}

FZGridCoordinate UZGridsLibrary::MakeZGridCoordinateFromX(int32 InX)
{
	return FZGridCoordinate(InX);
}
