// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ZGrids.h"

#define ZGRIDS_LOG(Verbosity, Format, ...) \
{ \
	UE_LOG(LogZGrids, Verbosity, Format, ##__VA_ARGS__); \
}
