// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CSV.h"
#include "TimerManager.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LoggingManager.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYPROJECT2_API ULoggingManager : public UActorComponent
{
	GENERATED_BODY()
private:
	CSV Csv;
	FTimerHandle Handle;

public:

	UPROPERTY(EditAnywhere, Category = "LoggingManager")
		FString Filename;

	UPROPERTY(EditAnywhere, Category = "LoggingManager")
	FString Path; // Always starts at project Path

		//UPROPERTY(EditAnywhere, Category = "LoggingManager")
		//bool bUpdateEveryFrame;

	UPROPERTY(EditAnywhere, Category = "LoggingManager")
	ACharacter* Player;
	UPROPERTY(EditAnywhere, Category = "LoggingManager")
	APawn* TargetPawn;

	UPROPERTY(EditAnywhere, Category = "LoggingManager")
	float LoggingStartTime; // Time at Logging Start
	UPROPERTY(EditAnywhere, Category = "LoggingManager")
	float LoggingTimeInterval; // Time between each logging call
	UPROPERTY(EditAnywhere, Category = "LoggingManager")
	float LoggingStopTime; // Logging Duration 
	UPROPERTY(EditAnywhere, Category = "LoggingManager")
	float LookingDistance; // The distance to track the Player's View Direction. 

public:
	// Sets default values for this component's properties
	ULoggingManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void LogData();
	void GetViewDirection(FVector*, FString*);

};
