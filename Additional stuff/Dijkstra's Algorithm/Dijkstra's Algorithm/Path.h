#pragma once

struct Path
{
    std::vector<Edge> m_edges;

    float GetDistance() const;
    float GetHValue() const;
    Node* GetLastNode() const;
    void Print();

    // Path's distance can be returned as a float
    operator float() const { return GetDistance(); }
};

float Path::GetDistance() const
{
    float distance = 0;
    for (auto& edge : m_edges)
    {
        distance += edge.m_Distance;
    }
    return distance;
}

float Path::GetHValue() const
{
    float distance = 0;
    for (auto& edge : m_edges)
    {
        edge.m_Distance;
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

void Path::Print()
{
    std::cout << "Path: ";
    for (auto& edge : m_edges)
        std::cout << edge.m_ToNode->m_Name;
    std::cout << " (" << *this << ")" << std::endl;
}