#pragma once

class Character;

struct Vector2D
{
public:
    int x = 0;
    int y = 0;
};

class GridNode
{
private:
    
    GridNode* UpNode = nullptr;
    GridNode* DownNode = nullptr;
    GridNode* RightNode = nullptr;
    GridNode* LeftNode = nullptr;
    Character* CharacterInNode = nullptr;
    Vector2D GridPosition;


public:
    GridNode();

    GridNode(const int InX, const int InY);

    ~GridNode();

    GridNode* GetUpNode() { return UpNode; }

    GridNode* GetDownNode() { return DownNode; }

    GridNode* GetRightNode() { return RightNode; }

    GridNode* GetLeftNode() { return LeftNode; }

    Character* GetCharInNode() { return CharacterInNode; }

    Vector2D GetNodePosition() { return GridPosition;  }

    void SetUpNode(GridNode* Node);

    void SetDownNode(GridNode* Node);

    void SetRightNode(GridNode* Node);

    void SetLeftNode(GridNode* Node);

    void SetCharacter(Character* Char);

    inline void SetGridPosition(const int InX, const int InY)
    {
        GridPosition.x = InX;
        GridPosition.y = InY;
    }

    void ClearNode();

    bool IsNodeOccupied();
};