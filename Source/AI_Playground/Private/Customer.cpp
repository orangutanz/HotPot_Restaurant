// Fill out your copyright notice in the Description page of Project Settings.


#include "Customer.h"

// Sets default values
ACustomer::ACustomer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACustomer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACustomer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACustomer::Reset()
{

}

void ACustomer::SetSeat(ACustomer_Seat& seat, int seatNumber)
{
	seat.SetOccupied(true);
	mSeatPtr = &seat;
}
