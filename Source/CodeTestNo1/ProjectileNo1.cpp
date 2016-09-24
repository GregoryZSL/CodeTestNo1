// Fill out your copyright notice in the Description page of Project Settings.

#include "CodeTestNo1.h"
#include "ProjectileNo1.h"


// Sets default values
AProjectileNo1::AProjectileNo1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProjectileNo1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectileNo1::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

