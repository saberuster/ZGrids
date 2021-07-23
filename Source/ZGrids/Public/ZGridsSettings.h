// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ZGridsSettings.generated.h"

/**
 * 
 */
UCLASS(Config=Engine, meta=(DisplayName="ZGrids"))
class ZGRIDS_API UZGridsSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:

	UZGridsSettings();

	
	UPROPERTY(noclear, EditAnywhere, Category="ZGrids", meta=(MetaClass="ZGrid"))
	FSoftClassPath DefaultGridClass;

	UPROPERTY(EditAnywhere, Config, Category="ZGrids")
	int32 MaxCoordinateX = INT32_MAX;

	UPROPERTY(EditAnywhere, Config, Category="ZGrids")
	int32 MinCoordinateX = 0;

	UPROPERTY(EditAnywhere, Config, Category="ZGrids")
	int32 MaxCoordinateY = INT32_MAX;

	UPROPERTY(EditAnywhere, Config, Category="ZGrids")
	int32 MinCoordinateY = 0;
	
	UPROPERTY(EditAnywhere, Config, Category="ZGrids")
	int32 MaxCoordinateZ = INT32_MAX;

	UPROPERTY(EditAnywhere, Config, Category="ZGrids")
	int32 MinCoordinateZ = 0;

	
	virtual FName GetCategoryName() const override;
};
