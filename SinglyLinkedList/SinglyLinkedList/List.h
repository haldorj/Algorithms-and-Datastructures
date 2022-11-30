#pragma once
#include <vector>

template<typename T>
class List
{
    Node<T>* Head;
    Node<T>* Tail;
    size_t NumberOfElements;
    T* SingleList;
public:
    List();
    List(std::initializer_list<T> initializer_list)
    {
        std::vector<T> temp = {initializer_list};
        
        for (int i = 0; i < temp.size(); ++i)
        {
            AddToTail(temp[i]);    
        }
    }
    void AddToTail(T data);
    void AddToHead(T data);
    void PrintData();
    void InsertAt(int index, T data);
    void RemoveAt(int index);
    Node<T>* FindNodeSpecific(int index);
    void RemoveAtHead();
    void RemoveAtTail();
    void SwapNodes(T x, T y);
    const T& operator[](size_t index) const;
    T& operator[](size_t index);
    size_t GetNumberOfElements() const { return NumberOfElements; }
    
    // Sorting
    void SelectionSort(List<T>& list);
};

template<typename T>
List<T>::List()
{
    Head = nullptr;
    Tail = nullptr;
    NumberOfElements = 0;
}

template<typename T>
void List<T>::AddToTail(T data)
{
    Node<T>* newNode = new Node<T>;
    newNode->Next = nullptr;
    newNode->Data = data;

    if (Head == nullptr)
    {
        Head = newNode;
        Tail = newNode;
    }
    else
    {
        newNode->Next = nullptr;
        Tail->Next = newNode;
        Tail = newNode;
    }

    NumberOfElements++;
}

template<typename T>
void List<T>::AddToHead(T data)
{
    Node<T>* newNode = new Node<T>;
    newNode->Next = nullptr;
    newNode->Data = data;

    if (Head == nullptr)
    {
        Head = newNode;
        Tail = newNode;
    }
    else
    {
        newNode->Next = Head;
        Head = newNode;
    }

    NumberOfElements++;
}

template<typename T>
void List<T>::PrintData()
{
    std::cout << "Prints from head to tail (start to end)" << std::endl;

    Node<T>* Temp = new Node<T>;
    // Create a node that points to Head.
    Temp = Head;
    // Loop through until it gets to a nullptr.
    while (Temp != nullptr)
    {
        std::cout << Temp->Data << " ";
        // Gets next element in the list.
        Temp = Temp->Next;
    }

    std::cout << std::endl;
}

template<typename T>
void List<T>::InsertAt(int index, T data)
{
    if(index == 0)
    {
        AddToHead(data);
        return;
    }
    
    Node<T>* p = Head;
    int i = 0;
    // if we dont reach end and until the we rich the point keep going forward 
    while (p->Next != NULL && i < index - 1) {
        p = p->Next;
        i++;
    }

    Node<T>* ANewNode = new Node<T>();
    ANewNode->Data = data;
    ANewNode->Next = p->Next;  // new node next pointer is pointing where the P was pointing 
    p->Next = ANewNode;   // now P pointer points to new node

    NumberOfElements++;
}

template<typename T>
void List<T>::RemoveAt(int index)
{
    Node<T>* p = Head;
    int i = 0;
    while (p->Next != NULL && i < index - 1)
    {
        p = p->Next;
        i++;
    }

    Node<T>* tempNode = p->Next;
    p->Next = p->Next->Next;   // because we deleted a node , we have to go two pointers forward. 
    tempNode->Next = NULL;
    delete tempNode;

    NumberOfElements--;
}

template <typename T>
Node<T>* List<T>::FindNodeSpecific(int index)
{
    Node<T>* p = Head;
    int i = 0;

    if (index == 0)
    {
        return Head;
    }
    
    while (p->Next != NULL && i < index - 1)
    {
        p = p->Next;
        i++;
    }

    if (index < 0 || index >= NumberOfElements)
    {
        std::cout << "Out of bounds!" << std::endl;
        return nullptr;
    }

    Node<T>* tempNode = p->Next;
    return tempNode;
}

template<typename T>
void List<T>::RemoveAtHead()
{
    if (Head == nullptr)
    {
        std::cout << "List is already empty." << std::endl;

        return;
    }

    Node<T>* tempNode = new Node<T>;

    tempNode = Head;
    Head = tempNode->Next;

    delete tempNode;

    NumberOfElements--;
}

template<typename T>
void List<T>::RemoveAtTail()
{
    if (Head == nullptr) std::cout << "List is already empty." << std::endl;

    else if (Head->Next == nullptr)
    {
        delete Head;
        NumberOfElements--;
    }

    else
    {
        Node<T>* Last = Head;
        Node<T>* SecondLast = Head;

        // traverse until end of list.
        while (Last->Next != nullptr)
        {
            SecondLast = Last;
            Last = Last->Next;
        }
        SecondLast->Next = nullptr;
        Tail = SecondLast;
        delete Last;
        NumberOfElements--;
    }
}

template <typename T>
void List<T>::SwapNodes(T x, T y)
{
    
}

template <typename T>
const T& List<T>::operator[](size_t index) const
{
    if (index < 0 || index >= NumberOfElements)
        throw("Out of bounds!");

    return FindNodeSpecific(index)->Data;
}

template <typename T>
T& List<T>::operator[](size_t index)
{
    if (index < 0 || index >= NumberOfElements)
        throw("Out of bounds!");

    return FindNodeSpecific(index)->Data;
}

template<typename T>
void List<T>::SelectionSort(List<T>& list)
{
    size_t i, j, MinIndex;
    T Temp;

    std::cout << "Attempting selectionsort." << std::endl;
    std::cout << "Sorting..." << std::endl;

    for (i = 0; i < NumberOfElements - 1; i++)
    {
        MinIndex = i;

        for (j = i + 1; j < NumberOfElements; j++)
        {
            if (list[j] < list[MinIndex])
            {
                MinIndex = j;
            }
        }

        if (MinIndex != i)
        {
            Temp = list[i];
            list[i] = list[MinIndex];
            list[MinIndex] = Temp;
        }
    }
}