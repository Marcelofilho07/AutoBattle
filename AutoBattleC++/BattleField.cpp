#include "Grid.h"
#include "GridNode.h"
#include "BattleField.h"
#include "Character.h"
#include <iostream>

BattleField::BattleField()
{
    NumberOfPlayers = 0;
}

void BattleField::Setup()
{
    GameGrid = new Grid();
    TeamAPlayer = new Character();
    TeamBPlayer = new Character();
    CreateGrid(GameGrid);
    std::cout << "Set First Player Stats: " << std::endl;
    CreateCharacter(TeamAPlayer);
    std::cout << "Set Second Player Stats: " << std::endl;
    CreateCharacter(TeamBPlayer);
    TeamAPlayer->SetPlayerPosition(GameGrid->GetRoot());
    TeamBPlayer->SetPlayerPosition(GameGrid->GetTail());
    TeamAPlayer->SetTarget(TeamBPlayer);
    TeamBPlayer->SetTarget(TeamAPlayer);
    StartGame();
}

void BattleField::CreateGrid(Grid* OutGrid)
{
    int X;
    int Y;

    std::cout << "Set Grid Lenght: " << std::endl;

    std::cin >> X;    
    while (std::cin.fail()) 
    {
        std::cout << "Please input a number" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> X;
    }

    std::cout << "Set Grid Height: " << std::endl;

    std::cin >> Y;    
    while (std::cin.fail()) 
    {
        std::cout << "Please input a number" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> Y;
    }

    if ((X <= 1 && Y <= 1) || (X == 0 || Y == 0))
    {
        std::cout << "Invalid Height or Lenght. Try again" << std::endl;
        CreateGrid(OutGrid);
    }
    else
    {
        OutGrid->PopulateGrid(X, Y);
    }
}

void BattleField::CreateCharacter(Character* NewChar)
{
    float Health;
    float Damage;
    float DamageMultiplier;
    int Movements;
    char Icon;

    std::cout << "Set new Player Health: " << std::endl;

    std::cin >> Health;
    while (std::cin.fail()) 
    {
        std::cout << "Please input a number" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> Health;
    }
    

    std::cout << "Set new Player Damage: " << std::endl;

    std::cin >> Damage;
    while (std::cin.fail()) 
    {
        std::cout << "Please input a number" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> Damage;
    }

    std::cout << "Set new Player Damage Multiplier: " << std::endl;

    std::cin >> DamageMultiplier;
    while (std::cin.fail()) 
    {
        std::cout << "Please input a number" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> DamageMultiplier;
    }

    std::cout << "Set new Player number of Movements: " << std::endl;

    std::cin >> Movements;

    while (std::cin.fail()) 
    {
        std::cout << "Please input a number" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> Movements;
    }

    std::cout << "Set new Player Icon: " << std::endl;

    std::cin >> Icon;
    while (std::cin.fail()) 
    {
        std::cout << "Please input a single letter" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> Icon;
    }
    
    NewChar->SetHealth(Health);
    NewChar->SetBaseDamage(Damage);
    NewChar->SetDamageMultiplier(DamageMultiplier);
    NewChar->SetMovement(Movements);
    NewChar->SetIconAndName(Icon);
    NumberOfPlayers++;
    NewChar->SetIndex(NumberOfPlayers);

    std::cout << "Player Created!" << std::endl << std::endl;
}

void BattleField::StartGame()
{
    GameGrid->DrawGrid();
    bool IsRunning = true;

    char WaitInput;
    std::cout << "Enter any key to start the round..." << std::endl;
    std::cin >> WaitInput;

    while (IsRunning)
    {
        IsRunning = HandleTurn();
    }

    if (TeamAPlayer->GetIsDead())
    {
        std::cout << "Second Player WINS!" << std::endl;
    }
    else
    {
        std::cout << "First Player WINS!" << std::endl;
    }

    int Choice;
    std::cout << "Do you want to start a new game? Yes - 1 / No - 0" << std::endl;
    std::cin >> Choice;    

    while (std::cin.fail()) 
    {
        std::cout << "Please input a number" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> Choice;
    }

    if (Choice)
    {
        ClearGame();
        Setup();
    }
}

void BattleField::ClearGame()
{
    delete GameGrid;
    GameGrid = nullptr;
}

bool BattleField::HandleTurn()
{
    char WaitInput;
    if (TeamAPlayer->GetIsDead())
    {
        return false;
    }
    TeamAPlayer->ExecuteTurn();
    GameGrid->DrawGrid();
    std::cout << "Enter any key to start the next turn..." << std::endl;
    std::cin >> WaitInput;
    if (TeamBPlayer->GetIsDead())
    {
        return false;
    }
    TeamBPlayer->ExecuteTurn();
    GameGrid->DrawGrid();
    std::cout << "Enter any key to start the next turn..." << std::endl;
    std::cin >> WaitInput;

    return true;
}