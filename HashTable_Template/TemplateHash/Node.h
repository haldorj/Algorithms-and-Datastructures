#pragma once

template <typename T>
struct Node
{
    T Data;
    Node* Next;

    int m_index;
    int m_element = 0;
};