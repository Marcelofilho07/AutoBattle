#pragma once
#include <list>
#include <iostream>

class Grid;

class Character;

class Types;

class BattleField
{
public:

	BattleField();

	Grid* GameGrid = nullptr;
	Character* TeamAPlayer = nullptr;
	Character* TeamBPlayer = nullptr;

	int Turn;

	void Setup();

	void CreateGrid(Grid* OutGrid);

	void CreateTeamACharacter();

	void CreateTeamBCharacter();

	void StartGame();

	bool HandleTurn();
};


