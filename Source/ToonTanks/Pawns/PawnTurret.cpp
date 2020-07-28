#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "PawnTurret.h"

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
}

void APawnTurret::CheckFireCondition()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire Condition Checked"));
}

void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

