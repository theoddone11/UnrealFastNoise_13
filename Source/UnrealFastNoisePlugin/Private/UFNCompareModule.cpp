// Fill out your copyright notice in the Description page of Project Settings.


#include "UFNCompareModule.h"


UUFNCompareModule::UUFNCompareModule(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
, InputModule1(nullptr)
, InputModule2(nullptr)
{}

float UUFNCompareModule::GetNoise3D(float InX, float InY, float InZ)
{
	if (!(InputModule1 && InputModule2))
	{
		return 0.0f;
	}
	/*switch (CompareModule)
	{
	case (EUFNCompare::ECV_GreaterThan): 
		{
			if (InputModule1->GetNoise3D())
		}
	
	}*/
	return 0.0f;
}

float UUFNCompareModule::GetNoise2D(float InX, float InY)
{
	return Super::GetNoise2D(InX, InY);
}