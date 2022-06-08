#include "GridNode.h"

GridNode::GridNode()
{
	SetGridPosition(0, 0);
}

GridNode::GridNode(const int InX, const int InY)
{
	SetGridPosition(InX, InY);
}

GridNode::~GridNode() {}

void GridNode::SetUpNode(GridNode* Node)
{
	if (Node != nullptr)
	{
		UpNode = Node;
	}
}

void GridNode::SetDownNode(GridNode* Node)
{
	if (Node != nullptr)
	{
		DownNode = Node;
	}
}

void GridNode::SetRightNode(GridNode* Node)
{
	if (Node != nullptr)
	{
		RightNode = Node;
	}
}

void GridNode::SetLeftNode(GridNode* Node)
{
	if (Node != nullptr)
	{
		LeftNode = Node;
	}
}

void GridNode::SetCharacter(Character* Char)
{
	if (Char != nullptr)
	{
		CharacterInNode = Char;
	}
}

void GridNode::ClearNode()
{
	if (this != nullptr)
	{
		CharacterInNode = nullptr;
	}
}

bool GridNode::IsNodeOccupied()
{
	if (this == nullptr)
	{
		return false;
	}

	if (CharacterInNode != nullptr)
	{
		return true;
	}

	return false;
}