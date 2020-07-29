#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "PawnTank.h"
#include "PawnTurret.h"

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::CheckFireCondition()
{
	if (!PlayerPawn || GetDistanceToPlayer() > FireRange)
		return;
	Fire();
}

float APawnTurret::GetDistanceToPlayer()
{
	if (!PlayerPawn)
		return 0.0f;
	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}

void APawnTurret::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!PlayerPawn || GetDistanceToPlayer() > FireRange)
		return;
	RotateTurret(PlayerPawn->GetActorLocation());
}

