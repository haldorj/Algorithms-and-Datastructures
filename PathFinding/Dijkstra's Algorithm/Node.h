#pragma once

struct Node
{
    char m_Name;
    bool m_Visited;
	float m_DistanceFromStart;
	float m_FCost;
    std::list<struct Edge> m_Edges; // for traversing to neighbouring nodes.
	
	Node* Prev;
	Node* Parent;

	Node(char name, float h_cost); // Construct new node
	void InsertEdge(const Edge& edge); // Insert an edge into the node

	// For A* Pathfinding:
	float m_HCost; // Heuristic cost / distance from end node
};

Node::Node(char name, float h_cost)
{
	m_Name = name;
	m_Visited = false;
	m_HCost = h_cost;
}

void Node::InsertEdge(const Edge& edge)
{
	m_Edges.push_back(edge);
}