#pragma once
#include "Grid.h"
#include "Character.h"
#include "Types.h"

class Character
{
public:

    Character();

    Character(float Health, const float BaseDamage, float DamageMultiplier, Types::CharacterClass CharClass);

    ~Character();

    float Health;
    float BaseDamage;
    float DamageMultiplier;

    bool IsDead;

    char Icon;

    bool TakeDamage(float amount);

    void Die();

    void WalkTo(bool CanWalk);

    void StartTurn(Grid* battlefield);

    bool CheckCloseTargets(Grid* battlefield);

    void Attack(Character* target);


};

