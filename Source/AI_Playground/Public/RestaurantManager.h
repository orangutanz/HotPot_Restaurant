// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Customer.h"
#include "Customer_Seat.h"
#include "RestaurantManager.generated.h"

UCLASS()
class AI_PLAYGROUND_API ARestaurantManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARestaurantManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Customer)
	TSubclassOf<ACustomer> customerBP;

	UFUNCTION(BlueprintCallable, Category = Customer)
	void NewCustomer();

	ACustomer* GetInactiveCustomer();
	ACustomer_Seat* GetEmptySeat();
	
private:
	TArray<ACustomer*> mCustomers;
	TArray<ACustomer_Seat*> mSeats;

	UPROPERTY(EditAnywhere)
	TArray<FVector> SpawnerPoints;

};
