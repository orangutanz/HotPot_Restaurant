// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Customer_Seat.generated.h"

UCLASS()
class AI_PLAYGROUND_API ACustomer_Seat : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACustomer_Seat();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool GetOccupied() { return mOccupied; }
	void SetOccupied(bool isOccupied) { mOccupied = isOccupied; }
	void CleanTable() { mOccupied = false; }
	

private:
	bool mOccupied = false;
	bool mSeat1 = false;
	bool mSeat2 = false;


};
