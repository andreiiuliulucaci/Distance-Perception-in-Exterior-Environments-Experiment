// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ReplayGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API UReplayGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UReplayGameInstance();
	UPROPERTY(EditDefaultsOnly, Category = "Replays")
		FString RecordingName;

	UPROPERTY(EditDefaultsOnly, Category = "Replays")
		FString FriendlyRecordingName;

	UFUNCTION(BlueprintCallable, Category = "Replays")
		void StartRecording(int IDTracker);

	UFUNCTION(BlueprintCallable, Category = "Replays")
		void StopRecording();

	UFUNCTION(BlueprintCallable, Category = "Replays")
		void StartReplay();

	UFUNCTION(BlueprintCallable, Category = "Replays")
		FString GetRecordingName();

};
