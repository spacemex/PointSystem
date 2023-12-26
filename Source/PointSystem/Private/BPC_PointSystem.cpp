// Fill out your copyright notice in the Description page of Project Settings.


#include "BPC_PointSystem.h"

// Sets default values for this component's properties
UBPC_PointSystem::UBPC_PointSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBPC_PointSystem::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBPC_PointSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
// Get CurrentPoints
int UBPC_PointSystem::GetCurrentPoints() const
{
	return CurrentPoints;
}

// Set CurrentPoints
int UBPC_PointSystem::SetCurrentPoints(int NewPoints)
{
	CurrentPoints = NewPoints;
	return CurrentPoints;
}

// Add Points To CurrentPoints
int UBPC_PointSystem::AddPoints(int PointsToAdd)
{
	CurrentPoints += PointsToAdd;
	return CurrentPoints;
}

// Remove Points From CurrentPoints (Clamps if Needed)
bool UBPC_PointSystem::RemovePoints(int PointsToRemove)
{
	if (PointsToRemove < 0 || PointsToRemove > CurrentPoints)
	{
		return false; //Removal Failed Due To Negative Input
	}
	CurrentPoints = FMath::Clamp(CurrentPoints - PointsToRemove, 0, MAX_int32);

	return true; //Points Removed Successfully
}
