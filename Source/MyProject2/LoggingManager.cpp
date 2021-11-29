// Fill out your copyright notice in the Description page of Project Settings.

#include "LoggingManager.h"
#include<string>
#include<vector>
#include"TimerManager.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
ULoggingManager::ULoggingManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// Assign Instance Variables Default Values

	LoggingStartTime = 0.0f;
	LoggingTimeInterval = 1.f;
	LoggingStopTime = 10.f;
	LookingDistance = 1100.f;
	Filename = TEXT("Participant_0");

	// ...
}


// Called when the game starts
void ULoggingManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	// Only 
	// Set Timer
	Path = FPaths::ProjectDir();
	UE_LOG(LogTemp, Warning, TEXT("Logging Begin"));
	GetWorld()->GetTimerManager().SetTimer(Handle, this, &ULoggingManager::LogData, LoggingTimeInterval, true, LoggingStartTime);
	TargetPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	
}


// Called every frame
void ULoggingManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void ULoggingManager::LogData()
{
	float Time = GetWorld()->GetTimeSeconds();
	//FVector PlayerLocation = Player->GetActorLocation();
	//FRotator PlayerRotation = Player->GetActorRotation();
	PawnLocation = TargetPawn->GetActorLocation();
	PawnRotation = TargetPawn->GetActorRotation();
	//FVector ObjectLocation; // The Location of Object that the Player looks at.
	//FString ObjectName;
	//GetViewDirection(&ObjectLocation, &ObjectName);

	// Converts all floating point values to single string
	string Values = Csv.CSVFormat(vector<float> {
		PawnLocation.X, PawnLocation.Y, PawnLocation.Z, // Player Location
			PawnRotation.Pitch, PawnRotation.Yaw, PawnRotation.Roll, // Player Rotation
			Time // Instance Time
	});

	//Values += string(TCHAR_TO_UTF8(*ObjectName)) + ";"; // Add Object Name as the element and it is converted to a string.
	//FString SomeString(Values.c_str());
	Csv.AddRow(Values);

	if (Time - LoggingStartTime >= LoggingStopTime)
	{
		GetWorld()->GetTimerManager().ClearTimer(Handle);
		Csv.WriteCSVFile(string(TCHAR_TO_UTF8(*Filename)), string(TCHAR_TO_UTF8(*Path)));
		UE_LOG(LogTemp, Warning, TEXT("Logging End"));
	}

}

void ULoggingManager::GetViewDirection(FVector* Point, FString* Name)
{
	FHitResult OutHit;
	FVector Start = TargetPawn->GetActorLocation();
	FVector End = Start + TargetPawn->GetActorForwardVector() * LookingDistance;

	if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECollisionChannel::ECC_Visibility))
	{
		*Point = OutHit.GetActor()->GetActorLocation();
		*Name = OutHit.GetActor()->GetName();

	}
}

