#pragma once
//size of table

template <typename T>
class hash_table : public Person
{
    static const T TABLE_SIZE = 10;

public:
    size_t HashFunction(std::string name);
    void InitializeHashTable();
    void PrintTable();
    bool Insert(Person* person);
    Person* Lookup(std::string name);
    Person* Delete(std::string name);
    
    // Hashtable: Array of Person pointers
    Person* HashTable[TABLE_SIZE];
};

template <typename T>
size_t hash_table<T>::HashFunction(std::string name)
{
    size_t Length;
    
    Length = name.length(); 
    size_t HashValue = 0;
    
    for (size_t i = 0; i < Length; i++)
    {
        HashValue += name[i];
        HashValue = (HashValue * name[i]) % TABLE_SIZE;
    }
    
    return HashValue;
}

template <typename T>
void hash_table<T>::InitializeHashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        HashTable[i] = nullptr;
    }
}

template <typename T>
void hash_table<T>:: PrintTable()
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

template <typename T>
bool hash_table<T>:: Insert(Person* person)
{
    if (person == nullptr) return  false;
    // Get index by using hashfunc
    int index = HashFunction(person->Name);
    // If index is occupied
    person->Next = HashTable[index];
    HashTable[index] = person;
    return true;
}

template <typename T>
Person* hash_table<T>::Lookup(std::string name)
{
    int index = HashFunction(name);
    Person* Temp = HashTable[index];
    while (Temp != nullptr && Temp->Name != name)
    {
        Temp = Temp->Next;
    }
    return Temp;
}

template <typename T>
Person* hash_table<T>:: Delete(std::string name)
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