#include "Grid.h"
#include "GridNode.h"
#include "Types.h"
#include <iostream>


Grid::Grid()
{
    GridRoot = nullptr;
}

Grid::Grid(int Lines, int Columns)
{

}

Grid::~Grid() 
{

}

void Grid::PopulateGrid(const int InX, const int InY)
{
    GridNode** GridTest = new GridNode*[InX];

    for (int i = 0; i < InX; i++)
    {
        GridTest[i] = new GridNode[InY];
        for (int j = 0; j < InY; j++)
        {
            GridTest[i][j] = GridNode(i, j);
        }
    }

    for (int i = 0; i < InX; i++)
    {
        for (int j = 0; j < InY; j++)
        {
            if (j != 0)
            {
                GridTest[i][j].SetUpNode(&GridTest[i][(j - 1)]);
            }
            if (j < (InY - 1))
            {
                GridTest[i][j].SetDownNode(&GridTest[i][j + 1]);
            }
            if (i != 0)
            {
                GridTest[i][j].SetLeftNode(&GridTest[i - 1][j]);
            }
            if (i < (InX - 1))
            {
                GridTest[i][j].SetRightNode(&GridTest[i + 1][ j]);
            }
        }
    }
    if (&GridTest[0][0] != nullptr)
    {
        GridRoot = &GridTest[0][0];
    }
}

void Grid::DrawGrid()
{
    GridNode* n = GridRoot;
    GridNode* RowFirst = GridRoot;
    while (n != nullptr)
    {
        std::cout << "[" << n->GetNodePosition().x << ", " << n->GetNodePosition().y << "] ";

        if (n->GetRightNode() != nullptr)
        {
            n = n->GetRightNode();
        }
        else if (RowFirst->GetDownNode() != nullptr)
        {
            std::cout << std::endl;
            n = RowFirst->GetDownNode();
            RowFirst = RowFirst->GetDownNode();
        }
        else
        {
            std::cout << std::endl;
            n = nullptr;
        }
    }
}