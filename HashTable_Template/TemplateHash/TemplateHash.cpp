#include <iostream>
#include <assert.h>

#include "Node.h"
#include "HashTable.h"
#include "HashT_OpenAdressing.h"

const int size = 10;

int main()
{
    open_adressing<int> hashTable;

    hashTable.InitializeHashTable();
    
    hashTable.Insert(55);
    hashTable.Insert(123);
    hashTable.Insert(23);
    hashTable.Insert(11);
    hashTable.Insert(9);
    hashTable.Insert(7);
    hashTable.Insert(10);
    hashTable.Insert(12);
    hashTable.Insert(99);
    hashTable.Insert(16);
    hashTable.Insert(32);

    hashTable.PrintTable();
    hashTable.Lookup(99);
    hashTable.Delete(99);
    hashTable.PrintTable();
    

    hash_table<char> ChashTable;
    
    ChashTable.InitializeHashTable();
    
    ChashTable.Insert('a');
    ChashTable.Insert('b');
    ChashTable.Insert('w');
    ChashTable.Insert('r');
    ChashTable.Insert('l');
    ChashTable.Insert('y');
    
    ChashTable.Lookup('r');
    ChashTable.Lookup('y');
    
    hash_table<std::string> ShashTable;
    
    ShashTable.InitializeHashTable();
    
    ShashTable.Insert("abc");
    ShashTable.Insert("123");
    ShashTable.Insert("900");
    ShashTable.Insert("lll");
    ShashTable.Insert("lmao");
    ShashTable.Insert("1336");
    ShashTable.Insert("www");
    ShashTable.Insert("WWW");
    ShashTable.Insert("zzz");
    ShashTable.Insert("9321");
    
    hashTable.PrintTable();
    ChashTable.PrintTable();
    ShashTable.PrintTable();
    
    ShashTable.Lookup("900");
    ShashTable.Lookup("lmao");
    ShashTable.Lookup("www");
    ShashTable.Lookup("lll");
    
    // deleting element
    ShashTable.Delete("200");
    ShashTable.Delete("lll");
    
    ShashTable.PrintTable();
    
    return 0;
}