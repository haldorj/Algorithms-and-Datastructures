#include <iostream>
#include "HashTable.h"

const int size = 12;

int main()
{
    hash_table<int>* intTable = new hash_table<int>;

    // Node<int>* Newnode;
    // Newnode->Data = 3;
    
    intTable->InitializeHashTable();
    intTable->PrintTable();
    int arr[12] = {12,11,10,9,8,7,6,5,4,3,2,1,};

    for (int i = 0; i < size; i++)
    {
        intTable->Insert(arr[i]);
    }

    intTable->PrintTable();
    
    return 0;
}