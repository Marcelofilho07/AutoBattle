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
No need for this switch case here.
CreateEnemyCharacter() should not be inside CreatePlayerCharacter();
StartGame() should not be inside CreateEnemyCharacter;
Moved both those functions to Setup;

GetRandomInt(int min, int max) returning itself ad nausean was a great joke thanks.

"EnemyCharacter->target = PlayerCharacter;
PlayerCharacter->target = EnemyCharacter;"
changed this for a SetTarget function;

No reason for "StartTurn()";

Removed all "AlocatePlayersFunction";

Character.h:

Changed a lot of variables.
Changed a lot of functions.
Removed includes.
added Private and Public.

Character.cpp:
Removed namespace.
Removed many includes.

Die
kill
end the game?

completed changed how StartTurn works

Created a lot of new functions.

Grid.h:

removed includes.
added private/public.
changed variables
changed functions.
This one I did a lot of changes.

Grid.cpp:
redone almost everything at this point.

Types.h and Types.cpp:
Why do we have this?
Just deleted both. We don't need classes. The document never said we need classes ;)
