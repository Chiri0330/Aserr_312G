// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Resource_M.h"
#include "PlayerChar.generated.h"

UCLASS()
class ASERR_312G_API APlayerChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Functions
	UFUNCTION()
			void MoveForward(float axisValue);


	UFUNCTION()
			void MoveRight(float axisValue);

	UFUNCTION()
			void StartJump();

	UFUNCTION()
			void StopJump();

	UFUNCTION()
			void FindObject();

//Properties 
	UPROPERTY(VisibleAnywhere)
	        UCameraComponent* PlayerCamComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
			float Health = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
			float Hunger = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
			float Stamina = 100.f;

//ResourcesArray
	UPROPERTY(EditAnywhere, Category = "Resources")
			int Wood;

	UPROPERTY(EditAnywhere, Category = "Resources")
			int Stone;

	UPROPERTY(EditAnywhere, Category = "Resources")
			int Berry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
			TArray<int> ResourcesArray;

	UPROPERTY(EditAnywhere, Category = "Resources")
			TArray<FString> ResourcesNameArray;

//Functions Set Health, Hunger abd Stamina
	UFUNCTION(BlueprintCallable)
			void SetHealth(float amount);

	UFUNCTION(BlueprintCallable)
			void SetHunger(float amount);

	UFUNCTION(BlueprintCallable)
			void SetStamina(float amount);

	UFUNCTION(BlueprintCallable)
			void DecreaseStats();

//Resources Amount
	UFUNCTION()
	void GiveResource(float amount, FString resourceType);
};
