#include <iostream>
#include <string>


//size of table
const size_t TABLE_SIZE = 10;

struct Person
{
    std::string Name;
    int age;

    // Next ptr for linked list
    Person* Next;
};

// Hashtable: Array of Person pointers
Person* HashTable[TABLE_SIZE];

unsigned int HashFunction(std::string name)
{
    size_t Length;
    
    Length = name.length(); 
    unsigned int HashValue = 0;
    
    for (int i = 0; i < Length; i++)
    {
        HashValue += name[i];
        HashValue = (HashValue * name[i]) % TABLE_SIZE;
    }
    
    return HashValue;
}

void InitializeHashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        HashTable[i] = nullptr;
    }
}

void PrintTable()
{
    std::cout << "START" << std::endl;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (HashTable[i] == nullptr)
        {
            std::cout << "["<< i << "] " << "---" << std::endl;
        }
        else
        {
            std::cout << "["<< i << "]";
            
            Person* Temp = HashTable[i];
            while (Temp != nullptr)
            {
                std::cout << Temp->Name << " - ";
                Temp = Temp->Next;
            }
            std::cout << std::endl;
        }
    }
    std::cout << "END" << std::endl;
    std::cout << std::endl;
}

bool Insert(Person* person)
{
    if (person == nullptr) return  false;
    // Get index by using hashfunc
    int index = HashFunction(person->Name);
    // If index is occupied
    person->Next = HashTable[index];
    HashTable[index] = person;
    return true;
}

Person* Lookup(std::string name)
{
    int index = HashFunction(name);
    Person* Temp = HashTable[index];
    while (Temp != nullptr && Temp->Name != name)
    {
        Temp = Temp->Next;
    }
    return Temp;
}

Person* Delete(std::string name)
{
    int index = HashFunction(name);
    Person* Temp = HashTable[index];
    Person* Prev = nullptr;
    
    while (Temp != nullptr && Temp->Name != name)
    {
        Prev = Temp;
        Temp = Temp->Next;
    }
    if (Temp == nullptr) return nullptr;
    if (Prev == nullptr)
    {
        // deleting the head
        HashTable[index] = Temp->Next;
    }
    else
    {
        Prev->Next = Temp->Next;
    }
    return Temp;
}

int main()
{
    InitializeHashTable();
    PrintTable();

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

    Insert(&Jacob);
    Insert(&Natalie);
    Insert(&Sara);
    Insert(&Ron);
    Insert(&Jane);
    Insert(&Steven);
    Insert(&Edna);
    Insert(&Maren);
    Insert(&Eliza);
    Insert(&George);

    PrintTable();

    Person* Temp = Lookup("Jacob");
    if (Temp == nullptr) std::cout << "Not Found" << std::endl;
    else std::cout << "Found " << Temp->Name << std::endl;

    Delete("Ron");
    
    PrintTable();
    
    return 0;
}
