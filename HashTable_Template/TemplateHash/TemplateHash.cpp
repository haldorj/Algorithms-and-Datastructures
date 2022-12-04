#include <iostream>
#include "HashTable.h"

const int size = 10;

int main()
{
    // hash_table<std::string, std::string>* hashTable = new hash_table<std::string, std::string>;
    //
    // hashTable->Insert("Steven");
    // hashTable->Insert("John");
    // hashTable->Insert("Sara");
    // hashTable->Insert("Stewart");
    // hashTable->Insert("Johnny");
    // hashTable->Insert("Karen");

    hash_table<int> hashTable;

    hashTable.Insert(55);
    hashTable.Insert(123);
    hashTable.Insert(23);
    hashTable.Insert(11);
    hashTable.Insert(9);
    hashTable.Insert(7);
    
    hashTable.PrintTable();
    
    return 0;
}