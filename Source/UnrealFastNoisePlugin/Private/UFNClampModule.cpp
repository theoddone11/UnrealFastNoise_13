// Fill out your copyright notice in the Description page of Project Settings.


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

float UUFNClampModule::GetNoise3D(float InX, float InY, float InZ)
{

	/*if (!InputModule1 || !(bClampMin && bClampMax)){
		return 0.0f;
	}*/
	/*float O_n = InputModule1->GetNoise3D(InX, InY, InZ);
	if (bClampMin && bClampMax)
	{
		return FMath::ClampMin()

	}
	if (bClampMin)
	{
		return FMath::Clamp(O_n, ClampMin, O_n);
	}
	if (bClampMax)
	{
		return FMath::Clamp(O_n, O_n, ClampMax);
	}
	return 1000.f;*/
	if (!InputModule1){
		return 0.0f;
	}
	if (!bClampMin && !bClampMax){
		return InputModule1->GetNoise3D(InX, InY, InZ);
	}
		else if (!bClampMin && bClampMax){
		return InputModule1->GetNoise3D(InX, InY, FMath::Clamp(InZ, InZ, ClampMax));
		/*InZ = (InZ > ClampMax) ? ClampMax : InZ;
		return InputModule1->GetNoise3D(InX, InY, InZ);*/
	}
	else if (!bClampMax && bClampMin){
		return InputModule1->GetNoise3D(InX, InY, FMath::Clamp(InZ, ClampMin, InZ));
		/*InZ = (InZ < ClampMin) ? ClampMin : InZ;
		return InputModule1->GetNoise3D(InX, InY, InZ);*/
	}
	else
	{
		return InputModule1->GetNoise3D(InX, InY, FMath::Clamp(InZ, ClampMin, ClampMax));
	}
}

//does not work for 2D
float UUFNClampModule::GetNoise2D(float InX, float InY)
{
	if (!InputModule1){
		return 0.0f;
	}
	float z_out = InputModule1->GetNoise2D(InX, InY);
	
	if (!bClampMin && !bClampMax){
		return z_out;
	}
	else if (!bClampMin && bClampMax){
		return FMath::Clamp(z_out, z_out, ClampMax);
		/*InZ = (InZ > ClampMax) ? ClampMax : InZ;
		return InputModule1->GetNoise3D(InX, InY, InZ);*/
	}
	else if (!bClampMax && bClampMin){
		return FMath::Clamp(z_out,  ClampMin, z_out);
		/*InZ = (InZ < ClampMin) ? ClampMin : InZ;
		return InputModule1->GetNoise3D(InX, InY, InZ);*/
	}
	else
	{
		return FMath::Clamp(z_out,  ClampMin, ClampMax);
	}
}