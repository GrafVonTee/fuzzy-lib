// Fill out your copyright notice in the Description page of Project Settings.


#include "Term/Gaussian.h"
#include "Kismet/KismetMathLibrary.h"

void UGaussian::MakeRange()
{
	Super::MakeRange();

	float TempMean = Mean - LowerBound;

	for (int32 Index = 0; Index < ValueRange.Num(); ++Index)
	{
		ValueRange[Index] = UKismetMathLibrary::Exp(
			-1 * UKismetMathLibrary::Square(Index - Mean)
			/ (2 * Dist * Dist)
		);
	}
}

void UGaussian::Set(
	FString NameOther,
	int32 LowerBoundOther,
	int32 UpperBoundOther,
	float MeanOther,
	float DistOther
)
{
	Super::Set(NameOther, LowerBoundOther, UpperBoundOther);

	Mean = MeanOther;
	Dist = DistOther;
	MakeRange();
}
