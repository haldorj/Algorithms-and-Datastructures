#pragma once

struct Edge
{
    float m_Distance; // Distance/weight of edge
    Node* m_ToNode; // Pointer to node
    Edge(float distance, Node* to_node);
    
    operator float() const { return m_Distance; }
};

Edge::Edge(float distance, Node* to_node)
{
    m_Distance = distance;
    m_ToNode = to_node;
}