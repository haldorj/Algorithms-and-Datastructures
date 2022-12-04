#pragma once


static const int table_size = 10;

template<typename T>
int HashFunction(T key);
template<>
int HashFunction<std::string>(std::string key);

template <typename T>
class hash_table
{
public:
    void InitializeHashTable();
    void PrintTable();
    void Insert(T data);
    void Lookup(T data);
    void Delete(T data);
    
    // Hashtable: Array of pointers
    Node<T>* HashTable[table_size];
};

template<typename T>
int HashFunction(T key)
{
    assert(std::is_arithmetic_v<T>);
    return static_cast<int>(key) % table_size;
}

template<>
int HashFunction<std::string>(std::string key)
{
    int sum{};
    for (const char i : key)
    {
        sum += static_cast<size_t>(i);
    }
    return sum % table_size;
}

template <typename T>
void hash_table<T>::InitializeHashTable()
{
    for (int i = 0; i < table_size; i++)
    {
        HashTable[i] = nullptr;
    }
}

template <typename T>
void hash_table<T>::PrintTable()
{
    std::cout << "START" << std::endl;
    for (int i = 0; i < table_size; i++)
    {
        if (HashTable[i] == nullptr)
        {
            std::cout << "["<< i << "] " << "---" << std::endl;
        }
        else
        {
            std::cout << "["<< i << "]";
            
            Node<T>* Temp = HashTable[i];
            while (Temp != nullptr)
            {
                std::cout << " "<< Temp->Data << " -";
                Temp = Temp->Next;
            }
            std::cout << std::endl;
        }
    }
    std::cout << "END" << std::endl;
    std::cout << std::endl;
}

template <typename T>
void hash_table<T>::Insert(T data)
{
    // Get index by using hashfunction.
    size_t index = HashFunction<T>(data);
    // If index is occupied
    Node<T>* Temp = new Node<T>;
    Temp->Data = data;
    
    Temp->Next = HashTable[index];
    HashTable[index] = Temp;
}

template <typename T>
void hash_table<T>::Lookup(T data)
{
    int element = 1;
    size_t index = HashFunction(data);
    Node<T>* Temp = HashTable[index];
    while (Temp != nullptr && Temp->Data != data)
    {
        element++;
        Temp = Temp->Next;
    }
    Temp->m_index = index;
    Temp->m_element = element;

    if (Temp == nullptr) std::cout << "Not Found" << std::endl;
    else std::cout << "Found " << Temp->Data << " at index: " << Temp->m_index << " element number " << Temp->m_element << " in the list." << std::endl;
}

template <typename T>
void hash_table<T>::Delete(T data)
{
    int index = HashFunction(data);
    Node<T>* Temp = HashTable[index];
    Node<T>* Prev = nullptr;
    
    while (Temp != nullptr && Temp->Data != data)
    {
        Prev = Temp;
        Temp = Temp->Next;
    }
    if (Temp == nullptr)
    {
        std::cout << "Value " << data << " not in table." << std::endl;
        return;
    }
    if (Prev == nullptr)
    {
        // deleting the head
        HashTable[index] = Temp->Next;
        
    }
    else
    {
        Prev->Next = Temp->Next;
    }

    std::cout << "Deleting " << Temp->Data << "." << std::endl;
    delete Temp;
}
