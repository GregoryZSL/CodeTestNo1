// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "CodeTestNo1.h"
#include "CodeTestNo1GameMode.h"
#include "CodeTestNo1Character.h"

ACodeTestNo1GameMode::ACodeTestNo1GameMode()
{
	// set default pawn class to our character
	DefaultPawnClass = ACodeTestNo1Character::StaticClass();	
}
