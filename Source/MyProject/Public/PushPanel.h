// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InterractableBaseObject.h"
#include "BaseInterface.h"
#include "PushPanel.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API APushPanel : public AInterractableBaseObject, public IBaseInterface
{
	GENERATED_BODY()

public:

	APushPanel();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Default")
	TArray<AActor*> BindedActors;

	void Interract(bool IsActivate) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void MySetAction(bool Active);
	virtual void MySetAction_Implementation(bool Active) override;
};
