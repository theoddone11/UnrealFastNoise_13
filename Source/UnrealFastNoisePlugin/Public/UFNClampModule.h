// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UFNNoiseGenerator.h"
#include "UFNClampModule.generated.h"

/**
 * 
 */
UCLASS()
class UNREALFASTNOISEPLUGIN_API UUFNClampModule : public UUFNNoiseGenerator
{
	GENERATED_BODY()
	
	
	
public:
	UUFNClampModule(const FObjectInitializer& ObjectInitializer);

	float GetNoise3D(float InX, float InY, float InZ) override;
	float GetNoise2D(float InX, float InY) override;
	UPROPERTY()
	UUFNNoiseGenerator* InputModule1;
	UPROPERTY()
	UUFNNoiseGenerator* InputModule2;

	UPROPERTY()
	bool bClampMin = false;
	
	UPROPERTY()
	bool bClampMax = false;
	
	UPROPERTY()
	float ClampMin = 0.0f;
	
	UPROPERTY()
	float ClampMax = 0.0f;
	
};

