#pragma once
#include <list>
#include <iostream>

class Grid;

class Character;

class Types;

class LinkedList;

class BattleField
{
public:

	BattleField();

	Grid* GameGrid;
	LinkedList* AllPlayers;
	LinkedList* TeamAPlayers;
	LinkedList* TeamBPlayers;

	int Turn;

	void Setup();

	void CreateGrid(Grid* OutGrid);

	void CreateTeamACharacter();

	void CreateTeamBCharacter();

	void StartGame();

	bool HandleTurn();
};


