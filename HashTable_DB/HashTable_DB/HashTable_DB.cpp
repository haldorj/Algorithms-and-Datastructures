#include <iostream>
#include <string>

#include "Person.h"
#include "HashTable.h"

int main()
{
    hash_table<int>* Table = new hash_table<int>;
    
    Table->InitializeHashTable();
    Table->PrintTable();

    Person Jacob = {"Jacob", 32};
    Person Natalie = {"Natalie", 27};
    Person Sara = {"Sara", 19};
    Person Ron = {"Ron", 40};
    Person George = {"George", 23};
    Person Jane = {"Jane", 51};
    Person Steven = {"Steven", 23};
    Person Edna = {"Edna", 40};
    Person Maren = {"Maren", 51};
    Person Eliza = {"Eliza", 23};

    Table->Insert(&Jacob);
    Table->Insert(&Natalie);
    Table->Insert(&Sara);
    Table->Insert(&Ron);
    Table->Insert(&Jane);
    Table->Insert(&Steven);
    Table->Insert(&Edna);
    Table-> Insert(&Maren);
    Table->Insert(&Eliza);
    Table->Insert(&George);

    Table->PrintTable();

    Person* Temp = Table->Lookup("Jacob");
    if (Temp == nullptr) std::cout << "Not Found" << std::endl;
    else std::cout << "Found " << Temp->Name << std::endl;

    Table->Delete("Ron");
    
    Table->PrintTable();
    
    return 0;
}
