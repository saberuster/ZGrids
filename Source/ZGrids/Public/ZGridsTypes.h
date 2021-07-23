// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZGridsTypes.generated.h"


USTRUCT(BlueprintType, meta=(HasNativeMake="ZGrids.ZGridsLibrary.MakeZGridCoordinate"))
struct FZGridCoordinate
{
	GENERATED_BODY()

	FZGridCoordinate():X(TNumericLimits<int32>::Max()), Y(TNumericLimits<int32>::Max()), Z(TNumericLimits<int32>::Max()){}
	FZGridCoordinate(int32 InX, int32 InY, int32 InZ): X(InX), Y(InY), Z(InZ){}
	FZGridCoordinate(int32 InX, int32 InY): X(InX), Y(InY), Z(0){}
	FZGridCoordinate(int32 InX): X(InX), Y(0), Z(0){}

	UPROPERTY(BlueprintReadOnly)
	int32 X;

	UPROPERTY(BlueprintReadOnly)
	int32 Y;

	UPROPERTY(BlueprintReadOnly)
	int32 Z;

	bool IsValid() const;

	friend bool operator==(const FZGridCoordinate& Lhs, const FZGridCoordinate& RHS)
	{
		return Lhs.IsValid()
			&& RHS.IsValid()
			&& Lhs.X == RHS.X
			&& Lhs.Y == RHS.Y
			&& Lhs.Z == RHS.Z;
	}

	friend bool operator!=(const FZGridCoordinate& Lhs, const FZGridCoordinate& RHS)
	{
		return !(Lhs == RHS);
	}

	friend uint32 GetTypeHash(const FZGridCoordinate& Coordinate)
	{
		auto Hash = HashCombine(GetTypeHash(Coordinate.X),GetTypeHash(Coordinate.Y));
		Hash = HashCombine(Hash, GetTypeHash(Coordinate.Z));
		return Hash;
	}
	
};


USTRUCT(BlueprintType)
struct FZGridLayoutHandle 
{
	GENERATED_BODY()
	
	FZGridLayoutHandle():Handle(INDEX_NONE){}

	bool IsValid() const
	{
		return Handle != INDEX_NONE;
	}

	void GenerateNewHandle();

	friend bool operator==(const FZGridLayoutHandle& Lhs, const FZGridLayoutHandle& RHS)
	{
		return Lhs.Handle == RHS.Handle;
	}

	friend bool operator!=(const FZGridLayoutHandle& Lhs, const FZGridLayoutHandle& RHS)
	{
		return !(Lhs == RHS);
	}

	friend uint32 GetTypeHash(const FZGridLayoutHandle& GridLayoutHandle)
	{
		return ::GetTypeHash(GridLayoutHandle.Handle);
	}

private:

	UPROPERTY()
	int32 Handle;
};




