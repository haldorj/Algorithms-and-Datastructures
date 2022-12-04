#pragma once

template <typename T>
class open_adressing
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

template <typename T>
void open_adressing<T>::InitializeHashTable()
{
    for (int i = 0; i < table_size; i++)
    {
        HashTable[i] = nullptr;
    }
}

template <typename T>
void open_adressing<T>::PrintTable()
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
                std::cout << " "<< Temp->Data <<" -";
                Temp = Temp->Next;
            }
            std::cout << std::endl;
        }
    }
    std::cout << "END" << std::endl;
    std::cout << std::endl;
}

template <typename T>
void open_adressing<T>::Insert(T data)
{
    // Get index by using hashfunction.
    size_t index = HashFunction<T>(data);
    // If index is occupied
    for (int i = 0; i < table_size; i++)
    {
        int Try = (i + index) % table_size;
        if (HashTable[Try] == nullptr)
        {
            Node<T>* newNode = new Node<T>();
            newNode->Data = data;
            HashTable[Try] = newNode;
            return;
        }
    }
    std::cout << "Table is full." << std::endl;
}

template <typename T>
void open_adressing<T>::Lookup(T data)
{
    size_t index = HashFunction(data);
    for (int i = 0; i < table_size; i++)
    {
        int Try = (i + index) % table_size;
        if (HashTable[Try] != nullptr && HashTable[Try]->Data == data)
        {
            std::cout << "Found " << HashTable[Try]->Data << " at index: " << Try << std::endl;
            return;
        }
    }
    std::cout << "Not Found" << std::endl;
}

template <typename T>
void open_adressing<T>::Delete(T data)
{
    size_t index = HashFunction(data);
    for (int i = 0; i < table_size; i++)
    {
        int Try = (i + index) % table_size;
        if (HashTable[Try] != nullptr && HashTable[Try]->Data == data)
        {
            std::cout << "Deleting " << HashTable[Try]->Data << " at index: " << Try << std::endl;
            HashTable[Try] = nullptr;
            delete HashTable[Try];
            return;
        }
    }
    std::cout << "Not Found" << std::endl;
}
