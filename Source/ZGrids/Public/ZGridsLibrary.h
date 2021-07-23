// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ZGridsTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ZGridsLibrary.generated.h"

class UZGridsStateComponent;

/**
 * 
 */
UCLASS()
class ZGRIDS_API UZGridsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category="ZGrids", meta=(bIgnoreSelf="true", WorldContext="WorldContextObject", DisplayName = "GetZGridsStateComponent"))
	static UZGridsStateComponent* BP_GetZGridsStateComponent(const UObject* WorldContextObject);

	static UZGridsStateComponent* GetZGridsStateComponent(UWorld* InWorld);
	static UZGridsStateComponent* GetZGridsStateComponent(AGameStateBase* InGameState);

	UFUNCTION(BlueprintPure, Category="ZGrids", meta=(NativeMakeFunc))
	static FZGridCoordinate MakeZGridCoordinate(int32 InX, int32 InY, int32 InZ);

	UFUNCTION(BlueprintPure, Category="ZGrids")
	static FZGridCoordinate MakeZGridCoordinateFromXY(int32 InX, int32 InY);

	UFUNCTION(BlueprintPure, Category="ZGrids")
	static FZGridCoordinate MakeZGridCoordinateFromX(int32 InX);

};
