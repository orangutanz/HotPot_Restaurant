// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Customer_Seat.h"
#include "Customer.generated.h"

UENUM()
enum CustomerStatus
{
	SearchingForSeat     UMETA(DisplayName = "SearchingForSeat"),
	Waiting      UMETA(DisplayName = "Waiting"),
	VisitingBuffet   UMETA(DisplayName = "VisitingBuffet"),
	Eating   UMETA(DisplayName = "Eating"),
	Leaving   UMETA(DisplayName = "Leaving")
};

UENUM()
enum VisitBuffetType
{
	GetSause     UMETA(DisplayName = "GetSause"),
	GetFood      UMETA(DisplayName = "GetFood"),
	GetDrink   UMETA(DisplayName = "GetDrink")
};


UCLASS()
class AI_PLAYGROUND_API ACustomer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACustomer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Customer)
	TEnumAsByte<CustomerStatus> currentStatus;


	void Reset();
	bool GetActive() { return mActive; }
	bool GetIsFull() { return mFullness >= 80; }

	bool IsSeated() { return mSeatPtr != nullptr; }
	void SetSeat(ACustomer_Seat& seat, int seatNumber);
private:
	ACustomer_Seat* mSeatPtr = nullptr;
	bool mActive = false;
	bool mSeated = false;
	bool mHasHotPot = false;
	bool mHasSause = false;
	int mSeatNumber = 0;
	int mNumOfFood = 0;
	int mNumOfDrink = 0;
	int mFullness = 0;

};
