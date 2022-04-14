#pragma once

class Types;

class Grid;

class Character
{
public:
    Character();

    Character(const float InHealth, const float InBaseDamage, const float InDamageMultiplier, const int InMovement, const char InIcon);

    ~Character();

    void TakeDamage(const float InAmount);

    void Die();

    void Walk(int RightSteps, int UpSteps);

    void ExecuteTurn();

    bool CheckCloseToTarget();

    void Attack();

    void SetTarget(Character* NewTarget);

    void SetPlayerPosition(GridNode* Node);

    char GetIcon() { return Icon; }
private:


private:
    int index;

    int Movement;

    float Health;

    float BaseDamage;

    float DamageMultiplier;

    bool IsDead;

    char Icon;

    char* Name;

    Character* Target;

    GridNode* GridPosition;
};

