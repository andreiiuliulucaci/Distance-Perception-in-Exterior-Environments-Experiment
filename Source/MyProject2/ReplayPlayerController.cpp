// Fill out your copyright notice in the Description page of Project Settings.


#include "ReplayPlayerController.h"
#include "Engine/World.h"
#include "Engine/DemoNetDriver.h"

void AReplayPlayerController::RestartRecording()
{
	if (UWorld* World = GetWorld())
	{
		if (UDemoNetDriver* DemoDriver = World->DemoNetDriver)
		{
			DemoDriver->GotoTimeInSeconds(0.f);
		}
	}
}
void AReplayPlayerController::RecordPlay()
{
	if (UWorld* World = GetWorld())
	{
		if (UDemoNetDriver* DemoDriver = World->DemoNetDriver)
		{
			AWorldSettings* WorldSettings = World->GetWorldSettings();
			check(WorldSettings != nullptr);
			if (DemoDriver != nullptr && DemoDriver->ServerConnection != nullptr && DemoDriver->ServerConnection->OwningActor != nullptr)
			{
				APlayerController* PlayerController = Cast<APlayerController>(DemoDriver->ServerConnection->OwningActor);
				if (PlayerController != nullptr)
				{
					WorldSettings->SetPauserPlayerState(PlayerController->PlayerState);
				}
			}
		}

	}
}

/*void AReplayPlayerController::RecordPlay()
{
	if (UWorld* World = GetWorld())
	{
		if (UDemoNetDriver* DemoDriver = World->DemoNetDriver)
		{
			AWorldSettings* WorldSettings = World->GetWorldSettings();
			check(WorldSettings != nullptr);
			if (DemoDriver != nullptr && DemoDriver->ServerConnection != nullptr && DemoDriver->ServerConnection->OwningActor != nullptr)
			{
				APlayerController* PlayerController = Cast<APlayerController>(DemoDriver->ServerConnection->OwningActor);
				if (PlayerController != nullptr)
				{
					WorldSettings->SetPauserPlayerState(PlayerController->PlayerState);
				}
			}
		}

	}
}*/
void AReplayPlayerController::RecordPause()
{
	if (UWorld* World = GetWorld())
	{
		if (UDemoNetDriver* DemoDriver = World->DemoNetDriver)
		{
			AWorldSettings* WorldSettings = World->GetWorldSettings();
			check(WorldSettings != nullptr);
			WorldSettings->SetPauserPlayerState(nullptr);
		}
	}
}

void AReplayPlayerController::ReplaySkip()
{
	float currentReplayTime = 0.f;
	if (UWorld* World = GetWorld())
	{
		if (UDemoNetDriver* DemoDriver = World->DemoNetDriver)
		{
			currentReplayTime = DemoDriver->GetDemoCurrentTime();
			DemoDriver->GotoTimeInSeconds(currentReplayTime + 5);
		}
	}
}

void AReplayPlayerController::ReplayBackSkip()
{
	float currentReplayTime = 0.f;
	if (UWorld* World = GetWorld())
	{
		if (UDemoNetDriver* DemoDriver = World->DemoNetDriver)
		{
			currentReplayTime = DemoDriver->GetDemoCurrentTime();
			DemoDriver->GotoTimeInSeconds(currentReplayTime-5);
		}
	}

}
float AReplayPlayerController::GetCurrentReplayTime()
{
	float currentTime = 0.f;
	if (UWorld* World = GetWorld())
	{
		if (UDemoNetDriver* DemoDriver = World->DemoNetDriver)
		{
			currentTime = DemoDriver->GetDemoCurrentTime();
		}
	}
	return currentTime;
}

float AReplayPlayerController::GetTotalReplayTime()
{
	float totalTime = 0.f;
	if (UWorld* World = GetWorld())
	{
		if (UDemoNetDriver* DemoDriver = World->DemoNetDriver)
		{
			totalTime = DemoDriver->GetDemoTotalTime();
		}
	}
	return totalTime;
}

