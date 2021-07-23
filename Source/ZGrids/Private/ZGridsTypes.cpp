// Fill out your copyright notice in the Description page of Project Settings.


#include "ZGridsTypes.h"

#include "ZGridsSettings.h"

bool FZGridCoordinate::IsValid() const
{
	const auto Settings = GetDefault<UZGridsSettings>();
	return X >= Settings->MinCoordinateX && X < Settings->MaxCoordinateX
		&& Y >= Settings->MinCoordinateY && Y < Settings->MaxCoordinateY
		&& Z >= Settings->MinCoordinateZ && Z < Settings->MaxCoordinateZ;
}

void FZGridLayoutHandle::GenerateNewHandle()
{
	static int32 GHandle = 1;
	Handle = GHandle++;
}
