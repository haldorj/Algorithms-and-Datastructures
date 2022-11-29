#pragma once

struct Node
{
    char m_Name;
    bool m_Visited;
    std::list<struct Edge> m_Edges;

	Node(char name);
	void InsertEdge(const Edge& edge);
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