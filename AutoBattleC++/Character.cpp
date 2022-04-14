#include "Grid.h"
#include "GridNode.h"
#include "Character.h"
#include "Types.h"
#include "Character.h"
#include <vector>
#include <algorithm>

Character::Character()
{
    IsDead = false;
    Health = 1.f;
    BaseDamage = 0.f;
    DamageMultiplier = 1.f;
}

Character::Character(const float InHealth, const float InBaseDamage, const float InDamageMultiplier, const int InMovement, const char InIcon)
{
    IsDead = false;
    Health = InHealth;
    BaseDamage = InBaseDamage;
    DamageMultiplier = InDamageMultiplier;
    Movement = InMovement;
    Icon = InIcon;
}

Character::~Character() {}

void Character::TakeDamage(const float InAmount) 
{
    Health -= (InAmount * DamageMultiplier);
	if (Health <= 0) 
	{
		Die();
	}
}


void Character::Die() 
{
    IsDead = true;
}

void Character::Walk(int RightSteps, int UpSteps) 
{
    int Moves = Movement;
    if (RightSteps > 0)
    {
        for (int i = 0; i < RightSteps && Moves > 0; i++)
        {
            SetPlayerPosition(GridPosition->GetRightNode());
            Moves--;
        }
    }
    else
    {
        for (int i = 0; i < -RightSteps && Moves > 0; i++)
        {
            SetPlayerPosition(GridPosition->GetLeftNode());
            Moves--;
        }
    }

    if (UpSteps > 0)
    {
        for (int i = 0; i < UpSteps && Moves > 0; i++)
        {
            SetPlayerPosition(GridPosition->GetUpNode());
            Moves--;
        }
    }
    else
    {
        for (int i = 0; i < -UpSteps && Moves > 0; i++)
        {
            SetPlayerPosition(GridPosition->GetDownNode());
            Moves--;
        }
    }
}

void Character::SetPlayerPosition(GridNode* Node)
{
    if (Node != NULL && !Node->IsNodeOccupied())
    {
        GridPosition->ClearNode();
        GridPosition = Node;
        Node->SetCharacter(this);
    }
}



void Character::ExecuteTurn()
{
    if (CheckCloseToTarget())
    {
        Attack();
    }
    else
    {
        Walk(Target->GridPosition->GetNodePosition().x - GridPosition->GetNodePosition().x, GridPosition->GetNodePosition().y - Target->GridPosition->GetNodePosition().y);
    }

    if (CheckCloseToTarget())
    {
        Attack();
    }
}

bool Character::CheckCloseToTarget()
{
    if (GridPosition->GetUpNode()->IsNodeOccupied() || GridPosition->GetDownNode()->IsNodeOccupied() || GridPosition->GetRightNode()->IsNodeOccupied() || GridPosition->GetLeftNode()->IsNodeOccupied())
    {
        return true;
    }

    return false;
}

void Character::Attack() 
{
    Target->TakeDamage(BaseDamage);
}

void Character::SetTarget(Character* NewTarget)
{
    Target = NewTarget;
}

