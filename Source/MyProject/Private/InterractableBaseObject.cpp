// Fill out your copyright notice in the Description page of Project Settings.


#include "InterractableBaseObject.h"

// Sets default values
AInterractableBaseObject::AInterractableBaseObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	Collider->SetupAttachment(RootComponent);
	Collider->SetBoxExtent(FVector(100.f, 100.f, 100.f), false);
	Collider->BodyInstance.SetCollisionProfileName("Zone");


}



void AInterractableBaseObject::Interract(bool IsActivate)
{

}

// Called when the game starts or when spawned
void AInterractableBaseObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInterractableBaseObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

