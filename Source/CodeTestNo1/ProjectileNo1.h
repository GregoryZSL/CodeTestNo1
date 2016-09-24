// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ProjectileNo1.generated.h"

UCLASS()
class CODETESTNO1_API AProjectileNo1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileNo1();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

protected:

	//set idle animation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbookComponent* ProjectileAnimation;

	// Damage Value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ProjectileProperties)
	float Damage;
	
	
};
