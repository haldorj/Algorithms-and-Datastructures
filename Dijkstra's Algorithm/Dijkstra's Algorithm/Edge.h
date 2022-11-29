#pragma once

struct Edge
{
    float m_Distance;
    Node* m_ToNode;
    Edge(float distance, Node* to_node);
    
    // bool operator > (const Kant& k) const { return m_vekt > k.m_vekt; }
    operator float() const { return m_Distance; }
};

Edge::Edge(float distance, Node* to_node)
{
    m_Distance = distance;
    m_ToNode = to_node;
}