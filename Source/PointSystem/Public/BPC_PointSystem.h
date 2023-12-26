// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BPC_PointSystem.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class POINTSYSTEM_API UBPC_PointSystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBPC_PointSystem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Functions

	/* Get Current Points*/
	UFUNCTION(BlueprintCallable, Category = "Points System")
	int GetCurrentPoints() const;

	/* Set Current Points*/
	UFUNCTION(BlueprintCallable, Category = "Points System")
	int SetCurrentPoints(int NewPoints);

	/* Add Points To Existing Current Points*/
	UFUNCTION(BlueprintCallable, Category = "Points System")
	int	AddPoints(int PointsToAdd);

	/* Remove Points From Existing Points (Clamps If Needed)*/
	UFUNCTION(BlueprintCallable, Category = "Points System")
	bool RemovePoints(int PointsToRemove);

	//Variables

	/* Starting Points*/
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "Points System")
	int CurrentPoints = 500;
};
