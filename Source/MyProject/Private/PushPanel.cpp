// Fill out your copyright notice in the Description page of Project Settings.


#include "PushPanel.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstance.h"

APushPanel::APushPanel()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Panel"));
	Mesh->SetupAttachment(RootComponent);
	Collider->OnComponentBeginOverlap.AddDynamic(this, &APushPanel::OnOverlapBegin);
	Collider->OnComponentEndOverlap.AddDynamic(this, &APushPanel::OnOverlapEnd);
}

void APushPanel::Interract(bool IsActivate)
{
	if (IsActivate)
	{
		Mesh->AddLocalOffset(FVector(0.0f, 0.0f, -10.0f), false, nullptr, ETeleportType::None);
	}

	else
	{
		Mesh->AddLocalOffset(FVector(0.0f, 0.0f, 10.0f), false, nullptr, ETeleportType::None);
	}
	for (auto& Item : BindedActors)
	{
		if (Item->Implements<UBaseInterface>())
		{
			Execute_MySetAction(Item,IsActivate);
		}
	}
}

void APushPanel::MySetAction_Implementation(bool Active)
{
	1;
}


void APushPanel::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Interract(true);
}

void APushPanel::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Interract(false);
}