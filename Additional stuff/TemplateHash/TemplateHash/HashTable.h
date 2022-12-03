#pragma once

template <typename T>
struct Node
{
    T Data;
    Node* Next;
};

template <typename T>
class hash_table
{
    //size of table
    static const size_t TABLE_SIZE = 10;

public:
    size_t HashFunction(T data);
    void InitializeHashTable();
    void PrintTable();
    bool Insert(T data);
    Node<T>* Lookup(Node<T>* data);
    Node<T>* Delete(Node<T>* data);
    
    // Hashtable: Array of pointers
    Node<T>* HashTable[TABLE_SIZE];
};

template <typename T>
size_t hash_table<T>::HashFunction(T data)
{
    const size_t Size = sizeof(data); 
    size_t HashValue = 0;
    
    for (size_t i = 0; i < Size; i++)
    {
        HashValue += data[i];
        HashValue = (HashValue * data[i]) % TABLE_SIZE;
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
void hash_table<T>::PrintTable()
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
    if (data == NULL) return  false;
    // Get index by using hashfunc
    size_t index = HashFunction(data);
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
