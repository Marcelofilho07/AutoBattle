#pragma once

class Types;

class Grid;

class Character
{
private:
    int Index;

    int Movement;

    float Health;

    float MaxHealth;

    float BaseDamage;

    float DamageMultiplier;

    bool IsDead;

    bool IsInvulnerable;

    bool IsEmpower;

    int EmpowerCharges;

    int InvulnerabilityCharges;

    char Icon;

    char Name;

    Character* Target;

    GridNode* GridPosition;

public:
    Character();

    ~Character();

    void SetHealth(const float InHealth);

    void SetBaseDamage(const float InBaseDamage);

    void SetDamageMultiplier(const float InDamageMultiplier);

    void SetMovement(const int InMovement);

    void SetIconAndName(const char InIcon);

    void SetTarget(Character* NewTarget);

    void SetPlayerPosition(GridNode* Node);

    void SetIndex(const int InIndex);

    char GetIcon() { return Icon; }

    bool GetIsDead() { return IsDead; }

    void ExecuteTurn();
private:
    void TakeDamage(const float InAmount);

    void Die();

    void Walk(int RightSteps, int UpSteps);

    bool CheckCloseToTarget();

    void Attack();

    void Empower();

    void Invulnerable();
};

