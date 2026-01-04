// Fill out your copyright notice in the Description page of Project Settings.
// theoddone11 added this module to midgen's UnrealFastNoise project based on the FastNoise api. 

#include "UFNCompareModule.h"


UUFNCompareModule::UUFNCompareModule(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
, InputModule1(nullptr)
, InputModule2(nullptr)
, CompareModule(EUFNCompare::ECV_NOUGHT)
{}

float UUFNCompareModule::GetNoise3D(float InX, float InY, float InZ)
{
	if (!(InputModule1 && InputModule2))
	{
		return 0.0f;
	}
	float Noise1 = InputModule1->GetNoise3D(InX, InY, InZ);
	float Noise2 = InputModule2->GetNoise3D(InX, InY, InZ);
	switch (CompareModule) {
		
		case (EUFNCompare::ECV_GreaterThan): 
			if (Noise1 > Noise2){
				return Noise1;
				}
			else{
				return Noise2;
			}
		
		case (EUFNCompare::ECV_LessThan):
			if (Noise1 < Noise2){
				return Noise1;
			}
			else{
				return Noise2;
			}
		case (EUFNCompare::ECV_NOUGHT):
			return (Noise1 / Noise2);
	
	default: 
		return (Noise1 + Noise2) / 2;
	}
}

float UUFNCompareModule::GetNoise2D(float InX, float InY)
{
	if (!(InputModule1 && InputModule2))
	{
		return 0.0f;
	}
	float Noise1 = InputModule1->GetNoise2D(InX, InY);
	float Noise2 = InputModule2->GetNoise2D(InX, InY);
	switch (CompareModule)
	{
	case (EUFNCompare::ECV_GreaterThan): 
		if (Noise1 > Noise2){
			return Noise1;
		}
		else{
			return Noise2;
		}
		
	case (EUFNCompare::ECV_LessThan):
		if (Noise1 < Noise2){
			return Noise1;
		}
		else{
			return Noise2;
		}		
	case (EUFNCompare::ECV_NOUGHT):
		return (Noise1 / Noise2);
	
	default: 
		return (Noise1 + Noise2) / 2;;
	}
}