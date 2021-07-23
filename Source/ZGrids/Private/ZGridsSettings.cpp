// Fill out your copyright notice in the Description page of Project Settings.


#include "ZGridsSettings.h"
#include "ZGrid.h"

UZGridsSettings::UZGridsSettings()
{
	DefaultGridClass = FSoftClassPath{UZGrid::StaticClass()};
}

FName UZGridsSettings::GetCategoryName() const
{
	return FName(TEXT("Plugins"));
}
