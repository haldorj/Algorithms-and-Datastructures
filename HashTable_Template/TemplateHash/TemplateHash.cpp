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

    hash_table<int>* hashTable = new hash_table<int>;

    hashTable->Insert(1423);
    hashTable->Insert(685);
    hashTable->Insert(111);
    hashTable->Insert(323);
    hashTable->Insert(999);
    hashTable->Insert(123);

    hashTable->PrintTable();
    
    return 0;
}