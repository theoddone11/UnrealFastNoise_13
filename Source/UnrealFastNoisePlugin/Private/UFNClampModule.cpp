// Fill out your copyright notice in the Description page of Project Settings.

// theoddone11 added this module to midgen's UnrealFastNoise project based on the FastNoise api. 
// It 'may' be redundant with the scale module, but I prefer this way of thinking about it.

#include "UFNClampModule.h"


UUFNClampModule::UUFNClampModule(const FObjectInitializer& ObjectInitializer)	
: Super(ObjectInitializer)
, InputModule1(nullptr)
, bClampMin(nullptr)
, bClampMax(nullptr)
, ClampMin(0.f)
, ClampMax(0.f)
{
}

float UUFNClampModule::GetNoise3D(float InX, float InY, float InZ){
	if (!InputModule1){
		return 0.0f;
	}
	if (!bClampMin && !bClampMax){
		return InputModule1->GetNoise3D(InX, InY, InZ);
	}
		else if (!bClampMin && bClampMax){
		return InputModule1->GetNoise3D(InX, InY, FMath::Clamp(InZ, InZ, ClampMax));
	}
	else if (!bClampMax && bClampMin){
		return InputModule1->GetNoise3D(InX, InY, FMath::Clamp(InZ, ClampMin, InZ));
	}
	else
	{
		return InputModule1->GetNoise3D(InX, InY, FMath::Clamp(InZ, ClampMin, ClampMax));
	}
}

float UUFNClampModule::GetNoise2D(float InX, float InY)
{
	if (!InputModule1){
		return (InX + InY);
	}
	float z_out = InputModule1->GetNoise2D(InX, InY);
	
	if (!bClampMin && !bClampMax){
		return z_out;
	}
	else if (!bClampMin && bClampMax){
		return FMath::Clamp(z_out, z_out, ClampMax);
	}
	else if (!bClampMax && bClampMin){
		return FMath::Clamp(z_out,  ClampMin, z_out);
	}
	else
	{
		return FMath::Clamp(z_out,  ClampMin, ClampMax);
	}
}