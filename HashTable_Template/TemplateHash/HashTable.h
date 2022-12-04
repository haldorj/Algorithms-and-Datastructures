#pragma once
#include <assert.h>

static const size_t table_size = 10;

template <typename T>
struct Node
{
    T Data;
    
    Node* Next;
};

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
    bool Insert(T data);
    Node<T>* Lookup(Node<T>* node);
    Node<T>* Delete(Node<T>* node);
    
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
int HashFunction<std::string>(std::string key) {
    // if key is text, get sum of ascii values mod capacity
    size_t sum{};
    for (const char i : key) {
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
                std::cout << Temp->Data << " - ";
                Temp = Temp->Next;
            }
            std::cout << std::endl;
        }
    }
    std::cout << "END" << std::endl;
    std::cout << std::endl;
}

template <typename T>
bool hash_table<T>::Insert(T data)
{
    //if (data == nullptr) return false;
    // Get index by using hashfunc
    size_t index = HashFunction<T>(data);
    // If index is occupied
    Node<T>* Temp = new Node<T>;
    Temp->Data = data;
    
    Temp->Next = HashTable[index];
    HashTable[index] = Temp;
    return true;
}

template <typename T>
Node<T>* hash_table<T>::Lookup(Node<T>* node)
{
    int index = HashFunction(node->Data);
    Node<T>* Temp = HashTable[index];
    while (Temp != nullptr && Temp->Data != node->Data)
    {
        Temp = Temp->Next;
    }
    return Temp;
}

template <typename T>
Node<T>* hash_table<T>::Delete(Node<T>* node)
{
    int index = HashFunction(node->Data);
    T* Temp = HashTable[index];
    T* Prev = nullptr;
    
    while (Temp != nullptr && Temp->Data != node->Data)
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
