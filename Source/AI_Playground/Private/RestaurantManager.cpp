// Fill out your copyright notice in the Description page of Project Settings.


#include "RestaurantManager.h"

#include "EngineUtils.h"

// Sets default values
ARestaurantManager::ARestaurantManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARestaurantManager::BeginPlay()
{
	Super::BeginPlay();

	UWorld* world = GetWorld();
	if (world)
	{
		auto pos = GetTransform();
		if (!SpawnerPoints.IsEmpty())
		{
			pos.AddToTranslation(SpawnerPoints[0]);
		}
		ACustomer* CustomerBPInstance = world->SpawnActor<ACustomer>(customerBP, pos);
		mCustomers.Add(CustomerBPInstance);
	}
	mSeats.Empty();
	//get all seats in the world
	for (TActorIterator<ACustomer_Seat> It(world, ACustomer_Seat::StaticClass()); It; ++It)
	{
		ACustomer_Seat* seat = *It;
		if (seat != NULL)
		{
			mSeats.Add(seat);
		}
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("CustomerPool %d"), mCustomers.Num()));
		GEngine->AddOnScreenDebugMessage(-2, 15.0f, FColor::Yellow, FString::Printf(TEXT("SeatNumber %d"), mSeats.Num()));
	}
}

// Called every frame
void ARestaurantManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 
	
}

ACustomer* ARestaurantManager::GetInactiveCustomer()
{
	for (auto i : mCustomers)
	{
		if (!i->GetActive())
		{
			i->Reset();
			
			return i;
		}
	}

	GEngine->AddOnScreenDebugMessage(-5, 15.0f, FColor::Yellow, FString::Printf(TEXT("!!RestaurantManager!! CustomerPool size %d is not enough."), mCustomers.Num()));
	return nullptr;
}

void ARestaurantManager::NewCustomer()
{
	UWorld* world = GetWorld();
	if (world)
	{
		auto pos = GetTransform();
		if (!SpawnerPoints.IsEmpty())
		{
			pos.AddToTranslation(SpawnerPoints[0]);
		}
		ACustomer* CustomerBPInstance = world->SpawnActor<ACustomer>(customerBP, pos);
		mCustomers.Add(CustomerBPInstance);

		// Get a reference to the "CustomerBP" class.
		//TSubclassOf<ACustomerBP> CustomerBPClass = ACustomerBP::StaticClass();

		// Spawn the instance of the "CustomerBP" class and store the reference to it.
		//ACustomerBP* CustomerBPInstance = World->SpawnActor<ACustomerBP>(CustomerBPClass, SpawnTransform);
	}
}

ACustomer_Seat* ARestaurantManager::GetEmptySeat()
{
	for (auto i : mSeats)
	{
		if (!i->GetOccupied())
		{
			return i;
		}
	}

	GEngine->AddOnScreenDebugMessage(-5, 15.0f, FColor::Yellow, FString::Printf(TEXT("!!RestaurantManager!! mSeats size %d is not enough."), mSeats.Num()));
	return nullptr;
}

