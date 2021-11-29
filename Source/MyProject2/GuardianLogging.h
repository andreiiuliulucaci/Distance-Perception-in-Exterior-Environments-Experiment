// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GuardianLogging.generated.h"

UCLASS(Blueprintable)
class MYPROJECT2_API AGuardianLogging : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGuardianLogging();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UFUNCTION()
	void PrintGuardianDimensions(FVector Dimensions);

};
