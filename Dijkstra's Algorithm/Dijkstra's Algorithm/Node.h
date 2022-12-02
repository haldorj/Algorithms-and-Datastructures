#pragma once

struct Node
{
    char m_Name;
    bool m_Visited;
	float m_DistanceFromStart;
    std::list<struct Edge> m_Edges; // for traversing to neighbouring nodes.
	
	Node* Prev;
	Node* Parent;

	Node(char name); // Construct new node
	void InsertEdge(const Edge& edge); // Insert an edge into the node
};

Node::Node(char name)
{
	m_Name = name;
	m_Visited = false;
}
void Node::InsertEdge(const Edge& edge)
{
	m_Edges.push_back(edge);
}