#pragma once

struct Path
{
    std::vector<Edge> m_edges;

    float GetDistance() const;
    Node* GetLastNode() const;

    operator float() const { return GetDistance(); }
};

float Path::GetDistance() const
{
    float distance = 0;
    for (auto& edge : m_edges)
    {
        distance += edge.m_Cost;
    }
    return distance;
}

Node* Path::GetLastNode() const
{
    if (!m_edges.empty())
    {
        return m_edges[m_edges.size() - 1].m_ToNode;
    }
    return nullptr;
}