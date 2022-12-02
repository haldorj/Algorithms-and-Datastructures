#pragma once

struct Node
{
    char m_Name;
    bool m_Visited;
    std::list<struct Edge> m_Edges;
	float H_Cost;

	Node(char name, float h_cost);
	void InsertEdge(const Edge& edge); // Insert an edge into the node
};

Node::Node(char name, float h_cost)
{
	m_Name = name;
	m_Visited = false;
	H_Cost = h_cost;
}
void Node::InsertEdge(const Edge& edge)
{
	m_Edges.push_back(edge);
}