// Fill out your copyright notice in the Description page of Project Settings.


#include "UFNClampModule.h"


UUFNClampModule::UUFNClampModule(const FObjectInitializer& ObjectInitializer)	
: Super(ObjectInitializer)
, bClampMin(nullptr)
, bClampMax(nullptr)
, ClampMin(0.0f)
, ClampMax(0.0f)
	 {}

float UUFNClampModule::GetNoise3D(float InX, float InY, float InZ)
{
	return Super::GetNoise3D(InX, InY, InZ);
}

float UUFNClampModule::GetNoise2D(float InX, float InY)
{
	return Super::GetNoise2D(InX, InY);
}