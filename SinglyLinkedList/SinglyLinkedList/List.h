#pragma once

template<typename T>
class List : public Node<T>
{
private:

public:
    Node<T>* Head;
    Node<T>* Tail;
    size_t NumberOfElements;

    List();
    void AddToTail(T data);
    void AddToHead(T data);
    void PrintData();
    void InsertAt(int index, T data);
    void RemoveAt(int index);
    void RemoveAtHead();
    void RemoveAtTail();
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
}

template<typename T>
void List<T>::RemoveAtHead()
{
    if (Head == nullptr) std::cout << "List is already empty." << std::endl;

    Node<T>* tempNode = new Node<T>;

    tempNode = Head;
    Head = tempNode->Next;

    delete tempNode;
}

template<typename T>
void List<T>::RemoveAtTail()
{
    if (Head == nullptr) std::cout << "List is already empty." << std::endl;

    else if (Head->Next == nullptr) delete Head;

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
    }
}
