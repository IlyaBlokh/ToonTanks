// Copyright Ilya Blokh

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameModeBase.generated.h"

class APawnTurret;
class APawnTank;
UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	void ActorDied(AActor* DeadActor);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game Loop", meta = (AllowPrivateAccess = "true"))
	int32 StartDelay = 3;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerWon);

private:
	APawnTank* PlayerTank;
	int32 TargetTurrets = 0;

	void HandleGameStart();
	void HandleGameOver(bool PlayerWon);
	int32 GetTargetTurretCount();
};
