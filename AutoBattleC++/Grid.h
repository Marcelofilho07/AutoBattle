#pragma once
#include <Vector>
#include "Types.h"

class GridNode;

class Grid
{
private:
    GridNode* GridRoot = nullptr;

public:

    Grid();
    Grid(int Lines, int Columns);
    ~Grid();
    
    void PopulateGrid(int SizeX, int SizeY);

    GridNode* GetRoot() { return GridRoot; }

    // prints the matrix that indicates the tiles of the battlefield
    void DrawGrid();
};

