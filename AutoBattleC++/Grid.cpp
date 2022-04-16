#include "Grid.h"
#include "GridNode.h"
#include "Character.h"
#include <iostream>


Grid::Grid()
{
    GridRoot = nullptr; 
    GridTail = nullptr;
}

Grid::~Grid() 
{

}

void Grid::PopulateGrid(const int InX, const int InY)
{
    GridNode** NewGrid = new GridNode*[InX];

    for (int i = 0; i < InX; i++)
    {
        NewGrid[i] = new GridNode[InY];
        for (int j = 0; j < InY; j++)
        {
            NewGrid[i][j] = GridNode(i, j);
        }
    }

    for (int i = 0; i < InX; i++)
    {
        for (int j = 0; j < InY; j++)
        {
            if (j != 0)
            {
                NewGrid[i][j].SetUpNode(&NewGrid[i][(j - 1)]);
            }
            if (j < (InY - 1))
            {
                NewGrid[i][j].SetDownNode(&NewGrid[i][j + 1]);
            }
            if (i != 0)
            {
                NewGrid[i][j].SetLeftNode(&NewGrid[i - 1][j]);
            }
            if (i < (InX - 1))
            {
                NewGrid[i][j].SetRightNode(&NewGrid[i + 1][ j]);
            }
        }
    }
    if (&NewGrid[0][0] != nullptr)
    {
        GridRoot = &NewGrid[0][0];
    }
    if (&NewGrid[InX - 1][InY - 1] != nullptr)
    {
        GridTail = &NewGrid[InX - 1][InY - 1];
    }
}

void Grid::DrawGrid()
{
    GridNode* n = GridRoot;
    GridNode* RowFirst = GridRoot;
    while (n != nullptr)
    {
        if (n->IsNodeOccupied())
        {
            if (n->GetCharInNode()->GetIsDead())
            {
                std::cout << "[" << "X" << "] ";
            }
            else
            {
                std::cout << "[" << n->GetCharInNode()->GetIcon() << "] ";
            }
        }
        else
        {
            std::cout << "[ " << "] ";
        }

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
    std::cout << "---------------------------------------------------------------- " << std::endl;
}