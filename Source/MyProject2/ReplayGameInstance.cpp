// Fill out your copyright notice in the Description page of Project Settings.


#include "ReplayGameInstance.h"

UReplayGameInstance::UReplayGameInstance()
{
	//FString IntAsString = FString::FromInt(IDTracker);
	RecordingName = "IDReplay "; //+ IntAsString;
	FriendlyRecordingName = "ID Replay"; //+ IntAsString;
}

void UReplayGameInstance::StartRecording(int IDTracker)
{
	IDTracker += 1;
	FString IntAsString = FString::FromInt(IDTracker);
	RecordingName = "IDReplay " + IntAsString;
	FriendlyRecordingName = "ID Replay" + IntAsString;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, RecordingName);
	StartRecordingReplay(RecordingName, FriendlyRecordingName);

}
void UReplayGameInstance::StopRecording()
{
	StopRecordingReplay();
}

void UReplayGameInstance::StartReplay()
{
	PlayReplay(RecordingName, nullptr);
}

FString UReplayGameInstance::GetRecordingName()
{
	return RecordingName;
}

