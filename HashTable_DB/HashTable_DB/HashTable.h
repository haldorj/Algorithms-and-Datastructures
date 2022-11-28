#pragma once


class hash_table : public Person
{
    //size of table
    static const size_t TABLE_SIZE = 10;
public:
    static size_t HashFunction(std::string name);
    void InitializeHashTable();
    void PrintTable() const;
    bool Insert(Person* person);
    Person* Lookup(std::string name) const;
    Person* Delete(std::string name);
    
    // Hashtable: Array of Person pointers
    Person* HashTable[TABLE_SIZE] = { nullptr };
};

inline size_t hash_table::HashFunction(std::string name)
{
    const size_t Length = name.length(); 
    size_t HashValue = 0;
    
    for (size_t i = 0; i < Length; i++)
    {
        HashValue += name[i];
        HashValue = (HashValue * name[i]) % TABLE_SIZE;
    }
    
    return HashValue;
}

inline void hash_table::InitializeHashTable()
{
    for (size_t i = 0; i < TABLE_SIZE; i++)
    {
        HashTable[i] = nullptr;
    }
}

inline void hash_table:: PrintTable() const
{
    std::cout << "START" << std::endl;
    for (size_t i = 0; i < TABLE_SIZE; i++)
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


inline bool hash_table:: Insert(Person* person)
{
    if (person == nullptr) return  false;
    // Get index by using hashfunc
    size_t index = HashFunction(person->Name);
    // If index is occupied
    person->Next = HashTable[index];
    HashTable[index] = person;
    return true;
}

inline Person* hash_table::Lookup(std::string name) const
{
    size_t index = HashFunction(name);
    Person* Temp = HashTable[index];
    while (Temp != nullptr && Temp->Name != name)
    {
        Temp = Temp->Next;
    }
    return Temp;
}

inline Person* hash_table:: Delete(std::string name)
{
    size_t index = HashFunction(name);
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