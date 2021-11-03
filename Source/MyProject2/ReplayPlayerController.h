// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ReplayPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API AReplayPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Replays")
	void RestartRecording();

	UFUNCTION(BlueprintCallable, Category = "Replays")
	void RecordPlay();

	UFUNCTION(BlueprintCallable, Category = "Replays")
	void RecordPause();

	UFUNCTION(BlueprintCallable, Category = "Replays")
		void ReplaySkip();

	UFUNCTION(BlueprintCallable, Category = "Replays")
		void ReplayBackSkip();

	UFUNCTION(BlueprintCallable, Category = "Replays")
		float GetCurrentReplayTime();
	
	UFUNCTION(BlueprintCallable, Category = "Replays")
		float GetTotalReplayTime();
};
