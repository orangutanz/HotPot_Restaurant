// Fill out your copyright notice in the Description page of Project Settings.


#include "Customer_Seat.h"

// Sets default values
ACustomer_Seat::ACustomer_Seat()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ACustomer_Seat::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACustomer_Seat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FTransform ACustomer_Seat::GetSeatWorldPosition(int index)
{
	if (mSeatPositions.Num() <= index)
	{
		return FTransform::Identity;
	}
	return mSeatPositions[index];
}

void ACustomer_Seat::AddSeatWorldPosition(const FTransform transform)
{
	mSeatPositions.Add(transform);
}

