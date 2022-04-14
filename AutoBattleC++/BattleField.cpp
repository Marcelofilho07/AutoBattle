#include "Grid.h"
#include "GridNode.h"
#include "BattleField.h"
#include "Types.h"
#include "Character.h"
#include <iostream>
#include <list>

BattleField::BattleField()
{
    Turn = 0;
    GameGrid = new Grid();
}

void BattleField::Setup()
{
    CreateGrid(GameGrid);
    CreateTeamACharacter();
    CreateTeamBCharacter();
    TeamAPlayer->SetPlayerPosition(GameGrid->GetRoot());
    TeamBPlayer->SetPlayerPosition(GameGrid->GetRoot()->GetRightNode()->GetRightNode()->GetRightNode()->GetRightNode()->GetRightNode()->GetRightNode()->GetRightNode()->GetRightNode()->GetRightNode()->GetRightNode()->GetRightNode()->GetRightNode()->GetDownNode()->GetDownNode()->GetDownNode()->GetDownNode()->GetDownNode()->GetDownNode()->GetDownNode()->GetDownNode()->GetDownNode()->GetDownNode()->GetDownNode()->GetDownNode()->GetDownNode()->GetDownNode());
    TeamAPlayer->SetTarget(TeamBPlayer);
    TeamBPlayer->SetTarget(TeamAPlayer);
    StartGame();
}

void BattleField::CreateGrid(Grid* OutGrid)
{
    OutGrid->PopulateGrid(15, 15);
}

void BattleField::CreateTeamACharacter()
{
   /* int Choice;

    std::cout << "Choose between one of these classes" << std::endl;

    std::cout << "[1] Paladin, [2] Warrior, [3] Cleric, [4] Archer" << std::endl;

    std::cin >> Choice;*/
    
    /*
    * TODO:::
    I'll need to create a Character Constructor and add it to the TeamA LinkedList
    */
    TeamAPlayer = new Character(100.f, 21.f, 0.4f, 2, 'L');
}

void BattleField::CreateTeamBCharacter()
{
    /*
    * TODO:::
    I'll need to create a Character Constructor and add it to the TeamB LinkedList
    */
    TeamBPlayer = new Character(100.f, 20.f, 0.4f, 2, 'B');
}

void BattleField::StartGame()
{
    bool IsRunning = true;
    while (IsRunning)
    {
        GameGrid->DrawGrid();
        IsRunning = HandleTurn();
    }
}

bool BattleField::HandleTurn()
{
    char WaitInput;
    TeamAPlayer->ExecuteTurn();
    TeamBPlayer->ExecuteTurn();
    std::cout << "Click on any key to start the next turn..." << std::endl;
    std::cin >> WaitInput;

    return true;
}