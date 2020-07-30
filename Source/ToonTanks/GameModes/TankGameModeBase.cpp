// Copyright Ilya Blokh


#include "TankGameModeBase.h"

void ATankGameModeBase::BeginPlay()
{
}

void ATankGameModeBase::ActorDied(AActor* DeadActor)
{
	UE_LOG(LogTemp, Warning, TEXT("A pawn died"));
}

void ATankGameModeBase::HandleGameStart()
{
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
}

