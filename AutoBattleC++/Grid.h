#pragma once

class GridNode;

class Grid
{
private:
    GridNode* GridRoot = nullptr;

    GridNode* GridTail = nullptr;

public:

    Grid();
    ~Grid();
    
    void PopulateGrid(int SizeX, int SizeY);

    GridNode* GetRoot() { return GridRoot; }

    GridNode* GetTail() { return GridTail; }

    void DrawGrid();
};

