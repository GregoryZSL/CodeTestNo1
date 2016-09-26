// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "PaperCharacter.h"
#include "CodeTestNo1Character.generated.h"

// This class is the default character for CodeTestNo1, and it is responsible for all
// physical interaction between the player and the world.
//
//   The capsule component (inherited from ACharacter) handles collision with the world
//   The CharacterMovementComponent (inherited from ACharacter) handles movement of the collision capsule
//   The Sprite component (inherited from APaperCharacter) handles the visuals

class UTextRenderComponent;

UCLASS(config=Game)
class ACodeTestNo1Character : public APaperCharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	// Shoot Arrow
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Arrow, meta = (AllowPrivateAccess = "true"))
	class UArrowComponent* ShootArrow;

	UTextRenderComponent* TextComponent;
	virtual void Tick(float DeltaSeconds) override;

protected:
	// The animation to play while running around
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Animations)
	class UPaperFlipbook* RunningAnimation;

	// The animation to play while idle (standing still)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* IdleAnimation;

	// The animation to play while jumping
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* JumpingAnimation;

	// The animation to play while hit
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* HitAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* StandingAttackAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* RunningAttackAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* JumpingAttackAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HeroState)
	bool IsAttacking;


	/** Called to choose the correct animation to play based on the character's movement state */
	void UpdateAnimation();

	/** Called for side to side input */
	void MoveRight(float Value);

	void UpdateCharacter();

	void Attack();

	void StopAttack();

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

	//Spawn projectileNo1
	UPROPERTY(EditAnywhere, Category = "SpawnProjectile")
	TSubclassOf<class AProjectileNo1> Projectile;

public:
	ACodeTestNo1Character();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

private:
	void SpawnProjectile();
	
};
