#pragma once

struct Edge
{
    Node* m_FromNode;
    Node* m_ToNode;
    float m_Cost;
    
    Edge(Node* from_node, Node* to_node, float cost);
    operator float() const { return m_Cost; }
};

Edge::Edge(Node* from_node, Node* to_node, float cost)
{
    m_FromNode = from_node;
    m_ToNode = to_node;
    m_Cost = cost;
}