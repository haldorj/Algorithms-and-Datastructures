#pragma once

template<typename T>
class Node
{
public:
    T Data;         // data to save, can be any data type
    Node* Next;     // pointer to the next node 
};