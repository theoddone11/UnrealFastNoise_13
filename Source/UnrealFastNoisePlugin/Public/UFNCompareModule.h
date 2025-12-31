// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UFNNoiseGenerator.h"
#include "UFNCompareModule.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EUFNCompare : uint8
{
	ECV_LessThan UMETA(DisplayName = "<"),
	ECV_GreaterThan UMETA(DisplayName = ">"),
	ECV_NOUGHT UMETA(DisplayName = "Ø")
};

UCLASS()
class UNREALFASTNOISEPLUGIN_API UUFNCompareModule : public UUFNNoiseGenerator
{
	GENERATED_BODY()
	
public:
	UUFNCompareModule(const FObjectInitializer& ObjectInitializer);

	float GetNoise3D(float InX, float InY, float InZ) override;
	

	
	float GetNoise2D(float InX, float InY) override;
	UPROPERTY()
	UUFNNoiseGenerator* InputModule1;
	UPROPERTY()
	UUFNNoiseGenerator* InputModule2;
	UPROPERTY()
	UUFNNoiseGenerator* SelectModule;

	UPROPERTY(EditInstanceOnly)
	EUFNCompare CompareModule;
	
	
};
