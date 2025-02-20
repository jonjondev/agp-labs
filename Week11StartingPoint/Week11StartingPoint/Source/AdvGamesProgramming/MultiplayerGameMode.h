// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MultiplayerGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ADVGAMESPROGRAMMING_API AMultiplayerGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessages) override;
	
	// -------------------- RESPAWN FUNCTIONS --------------------
	/**
	 * The main respawn function that will destroy the pawn and set the timer for the trigger respawn function.
	 * @param: Controller: The controller responsible for the pawn that died.
	 */
	void Respawn(AController* Controller);

	/**
	 * Will cause the default pawn to be respawned instantly. Call this from a timer in Respawn.
	 * @param Controller: The controller responsible for the pawn that died.
	 */
	UFUNCTION()
	void TriggerRespawn(AController* Controller);

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class APickup> WeaponPickupClass;



private:

	// ------------------- MANAGERS AND MAP -------------------
	class AProcedurallyGeneratedMap* ProceduralMap;
	class APickupManager* PickupManager;

};
