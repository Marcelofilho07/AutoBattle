#pragma once

class Grid;

class Character;

class Types;

class BattleField
{
private:
	Grid* GameGrid = nullptr;
	Character* TeamAPlayer = nullptr;
	Character* TeamBPlayer = nullptr;
	int NumberOfPlayers;

public:

	BattleField();

	void Setup();

private:
	void CreateGrid(Grid* OutGrid);

	void CreateCharacter(Character* NewChar);

	void StartGame();

	void ClearGame();

	bool HandleTurn();
};


