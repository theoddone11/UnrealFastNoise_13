#include "UnrealFastNoisePlugin/Public/UFNNoiseGenerator.h"


UUFNNoiseGenerator::UUFNNoiseGenerator(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

float UUFNNoiseGenerator::GetNoise2D(float InX, float InY){
	return -2.0f;
}

float UUFNNoiseGenerator::GetNoise2DV(FVector2D XY){
	return GetNoise2D(XY.X, XY.Y);
}

float UUFNNoiseGenerator::GetNoise3D(float InX, float InY, float InZ)
{
	return -2.0f;
}