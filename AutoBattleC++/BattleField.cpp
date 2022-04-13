#include "Grid.h"
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
    StartGame();
}

void BattleField::CreateGrid(Grid* OutGrid)
{
    OutGrid->PopulateGrid(15, 15);
}

void BattleField::CreateTeamACharacter()
{
    int Choice;

    std::cout << "Choose between one of these classes" << std::endl;

    std::cout << "[1] Paladin, [2] Warrior, [3] Cleric, [4] Archer" << std::endl;

    std::cin >> Choice;

    //Types::CharacterClass* NewCharacterClass = (Types::CharacterClass*)Choice;
    //std::cout << "Player Class Choice: " << NewCharacterClass << std::endl;;
    
    /*
    * TODO:::
    I'll need to create a Character Constructor and add it to the TeamA LinkedList
    */
}

void BattleField::CreateTeamBCharacter()
{
    Types::CharacterClass NewCharacterClass = (Types::CharacterClass)1; // ADD RANDOM NUM GENERATOR
    std::cout << "Enemy Class Choice: " << NewCharacterClass << std::endl;

    /*
    * TODO:::
    I'll need to create a Character Constructor and add it to the TeamB LinkedList
    */
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
    while(true)
    {
        //GO THROUGH ALL PLAYERS LINKED LIST AND MAKE THEN DO THEIR ACTIONS
        std::cout << "Click on any key to start the next turn..." << std::endl;
        std::cin;
        return false;
    }
    return true;
}