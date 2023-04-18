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

	UFUNCTION(BlueprintCallable, Category = Customer)
	bool GetOccupied() { return mOccupied; }

	UFUNCTION(BlueprintCallable, Category = Customer)
	void SetOccupied(bool isOccupied) { mOccupied = isOccupied; }

	UFUNCTION(BlueprintCallable, Category = Customer)
	void CleanTable() { mOccupied = false; }

	UFUNCTION(BlueprintCallable, Category = Customer)
	FTransform GetSeatWorldPosition(int index);

	UFUNCTION(BlueprintCallable, Category = Customer)
	void AddSeatWorldPosition(FTransform transform);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Customer)
	TArray<FTransform> mSeatPositions;

private:
	bool mOccupied = false;


};
