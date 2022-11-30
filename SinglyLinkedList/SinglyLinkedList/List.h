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
    const T& operator[](size_t index) const;
    T& operator[](size_t index);
    size_t GetNumberOfElements() const { return NumberOfElements; }
    
    // Sorting
    void SelectionSort(List<T>& list);
    void BubbleSort(List<T>& list);
    void MergeSort(List<T>& list);
    void QuickSort(List<T>& list);
    void HeapSort(List<T>& list);

private:
	// Sorting
	void MergeSortRecursion(List<T>& list, size_t left, size_t right);
    void MergeSortedArrays(List<T>& list, size_t left, size_t mid, size_t right);
	
    void QuickSortRecursion(List<T>& list, int low, int high);
    int Partition(List<T>& list, int low, int high);
	
	void Heapify(List<T>& list, int length, int i);
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
	if(index == 0)
	{
		RemoveAtHead();
		return;
	}
	
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

template<typename T>
void List<T>::BubbleSort(List<T>& list)
{
	bool Swapped = true;
	size_t j = 0;
	T Temp;

	std::cout << "Attempting bubblesort." << std::endl;
	std::cout << "Sorting..." << std::endl;

	while (Swapped) {
		Swapped = false;

		j++;
		for (size_t i = 0; i < NumberOfElements - j; i++) {
			if (list[i] > list[i + 1]) {
				Temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = Temp;
				Swapped = true;
			}
		}
	}
}

template<typename T>
void List<T>::MergeSort(List<T>& list)
{
	MergeSortRecursion(list, 0, NumberOfElements -1);
}

template<typename T>
void List<T>::MergeSortRecursion(List<T>& list, size_t left, size_t right)
{
	if (left < right)
	{
		size_t mid = left + (right - left) / 2;

		MergeSortRecursion(list, left, mid);
		MergeSortRecursion(list, mid + 1, right);

		MergeSortedArrays(list, left, mid, right);
	}
}

template<typename T>
void List<T>::MergeSortedArrays(List<T>& list, size_t left, size_t mid, size_t right)
{
	size_t LeftLength = mid - left + 1;
	size_t RightLength = right - mid;

	T* TempLeft = new T[LeftLength];
	T* TempRight = new T[RightLength];

	size_t i, j, k;

	for (i = 0; i < LeftLength; i++)
	{
		TempLeft[i] = list[left + i];
	}
	for (i = 0; i < RightLength; i++)
	{
		TempRight[i] = list[mid + 1 + i];
	}

	for (i = 0, j = 0, k = left; k <= right; k++)
	{
		if ((i < LeftLength) &&
			(j >= RightLength || TempLeft[i] <= TempRight[j]))
		{
			list[k] = TempLeft[i];
			i++;
		}
		else
		{
			list[k] = TempRight[j];
			j++;
		}
	}
}

template<typename T>
void List<T>::QuickSort(List<T>& list)
{
	std::cout << "Attempting quicksort." << std::endl;
	std::cout << "Sorting..." << std::endl;

	srand(time(NULL));
	QuickSortRecursion(list, 0, NumberOfElements - 1);
}

template<typename T>
void List<T>::QuickSortRecursion(List<T>& list, int low, int high)
{
	if (low < high)
	{
		int PivotIndex = Partition(list, low, high);
		QuickSortRecursion(list, low, PivotIndex - 1);
		QuickSortRecursion(list, PivotIndex + 1, high);
	}
}

template<typename T>
int List<T>::Partition(List<T>& list, int low, int high)
{
	int PivotIndex = low + (rand() % (high - low));

	if (PivotIndex != high)
	{
		std::swap(list[PivotIndex], list[high]);
	}

	T PivotValue = list[high];
	int i = low;

	for (int j = low; j < high; j++)
	{
		if (list[j] <= PivotValue)
		{
			std::swap(list[i], list[j]);
			i++;
		}
	}
	std::swap(list[i], list[high]);
	return i;
}

template<typename T>
void List<T>::HeapSort(List<T>& list)
{
	int length = NumberOfElements;
	std::cout << "Attempting heapsort." << std::endl;
	std::cout << "Sorting..." << std::endl;

	for (int i = length / 2 - 1; i >= 0; i--)
	{
		Heapify(list, length, i);
	}

	for (int i = length - 1; i > 0; i--)
	{
		std::swap(list[0], list[i]);
		Heapify(list, i, 0);
	}
}

template<typename T>
void List<T>::Heapify(List<T>& list, int length, int i)
{
	int Largest = i;
	int Left = 2 * i + 1;
	int Right = 2 * i + 2;

	if (Left < length && list[Left] > list[Largest])
		Largest = Left;

	if (Right < length && list[Right] > list[Largest])
		Largest = Right;


	if (Largest != i) 
	{
		Swap(list[i], list[Largest]);
		Heapify(list, length, Largest);
	}
}