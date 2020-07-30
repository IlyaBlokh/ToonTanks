// Copyright Ilya Blokh
#include "Engine/World.h"
#include "ToonTanks/GameModes/TankGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	Health = DefaultHealth;
	GameModeRef = Cast<ATankGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
}

void UHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage == 0 || Health <= 0)
		return;
	Health = FMath::Clamp(Health - Damage, 0.f, DefaultHealth);
	if (Health <= 0) {
		if (GameModeRef) {
			GameModeRef->ActorDied(GetOwner());
		}
		else
		{ 
			UE_LOG(LogTemp, Error, TEXT("Health component in %s misses Game Mode reference"), *GetOwner()->GetClass()->GetName());
		}
	}
}

