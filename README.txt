Fix List:

Using UE conding standart. Found at: https://docs.unrealengine.com/4.27/en-US/ProductionPipelines/DevelopmentSetup/CodingStandard/

AutoBattleC++.cpp:
Changing variable name;
no need for "new(Battlefield)"

Battlefield.h:

Removing some includes;
Foward declaring some classes;
Removed "using namespace std;" if I need to use std I'll call "std::...";
Removed int GetRandomInt(int min, int max);

Battlefield.cpp:
Removed "using namespace std;" if I need to use std I'll call "std::...";
Removed some includes;
Removed a double include;
Fixed indentation in class constructor;
No need to call setup inside class constructor;
Fixed a variable name;(first letter was lowercase)
Removed some blank spaces;
Deleted "int numberOfPossibleTiles". Never used;
We don't need to store our player choice in a string. He can input an integer;
Switch case desnecessário. Todas escolhas levam para o mesmo caminho.
CreateEnemyCharacter() should not be inside CreatePlayerCharacter();
StartGame() should not be inside CreateEnemyCharacter;
Moved both those functions to Setup;
I'm making a linked list to store characters;

"void BattleField::AlocatePlayers()
{
    AlocatePlayerCharacter();
}"
This is unnaceptable;

GetRandomInt(int min, int max) returning itself ad nausean was a great joke thanks.

"EnemyCharacter->target = PlayerCharacter;
PlayerCharacter->target = EnemyCharacter;" No need for this anymore

No reason for "StartTurn()";

Removed all "AlocatePlayersFunction";
