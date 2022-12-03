#pragma once
#include <vector>

template<typename T>
class List
{
    Node<T>* Head;
    Node<T>* Tail;
    size_t NumberOfElements;
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
    void RemoveAtHead();
    void RemoveAtTail();
	void RemoveDuplicates();

	Node<T>* FindNodeSpecific(size_t index);
    size_t GetNumberOfElements() const { return NumberOfElements; }

	void LinearSearch(List<T>& list, const T& value);
	std::string LinearSearchOutput(List<T>& list, const T& value);

	void BinarySearch(List<T>& list, const T& value);
	std::string BinarySearchOutput(List<T>& list, size_t left, size_t right, const T& value);
	
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
    int QuickSortPartition(List<T>& list, int low, int high);
	
	void Heapify(List<T>& list, int length, int i);
	
	void SwapNodes(T left, T right); // Swaps the actual nodes in the linked list (not values).
	
	const T& operator[](size_t index) const;
	T& operator[](size_t index);
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

    // Create a node that points to Head.
    Node<T>* Temp = Head;
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
Node<T>* List<T>::FindNodeSpecific(size_t index)
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
void List<T>::LinearSearch(List<T>& list, const T& value)
{
	std::cout << "Attempting linear search." << std::endl;
	std::cout << "Searching for " << value << "... " << std::endl;
	std::cout << LinearSearchOutput(list, value) << std::endl;
}

template<typename T>
std::string List<T>::LinearSearchOutput(List<T>& list, const T& value)
{
	for (size_t i = 0; i < NumberOfElements; i++)
	{
		if (value == list[i])
		{
			std::stringstream buffer;
			buffer << "The value " << value << " was found at the element with index " << i << "." << std::endl;
			std::string Success = buffer.str();
			return Success;
		}
	}
	return "No result";
}

template<typename T>
void List<T>::BinarySearch(List<T>& list, const T& value)
{
	std::cout << "Attempting binary search." << std::endl;
	std::cout << "Searching for " << value << "... " << std::endl;
	std::cout << BinarySearchOutput(list, 0, NumberOfElements - 1, value) << std::endl;
}

template<typename T>
std::string List<T>::BinarySearchOutput(List<T>& list, size_t left, size_t right, const T& value)
{
	if (right >= left) 
	{
		size_t mid = left + (right - left) / 2;

		if (list[mid] == value)
		{
			std::stringstream buffer;
			buffer << "The value " << value << " was found at the element with index " << mid << "." << std::endl;
			std::string Success = buffer.str();
			return Success;
		}
		if (list[mid] > value)
		{
			return BinarySearchOutput(list, left, mid - 1, value);
		}

		return BinarySearchOutput(list, mid + 1, right, value);
	}
	return "No result";
}

template<typename T>
void List<T>::RemoveAtHead()
{
    if (Head == nullptr)
    {
        std::cout << "List is already empty." << std::endl;

        return;
    }

    Node<T>* tempNode = Head;
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

template<class T>
void List<T>::RemoveDuplicates()
{
	std::cout << "Removing duplicate values from the list." << std::endl;

	if (Head == nullptr)
	{
		return;
	}
	Node<T>* Current = Head;

	while (Current->Next != nullptr) 
	{
		// Compares current node with next node.
		if (Current->Data == Current->Next->Data)
		{
			// Delete current if it holds the same value as the next node.
			DeleteNode(Current->Next);
		}
		else
		{
			// Move on to next node otherwise.
			Current = Current->Next;
		}
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

	// loop through all elements in list
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
        	SwapNodes(list[i], list[MinIndex]);
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
				SwapNodes(list[i], list[i+1]);
				Swapped = true;
			}
		}
	}
}

template<typename T>
void List<T>::MergeSort(List<T>& list)
{
	std::cout << "Attempting mergesort." << std::endl;
	std::cout << "Sorting..." << std::endl;
	
	// Pass in linked list, with the first and last element
	MergeSortRecursion(list, 0, NumberOfElements -1);
}

template<typename T>
void List<T>::MergeSortRecursion(List<T>& list, size_t left, size_t right)
{
	if (left < right)
	{
		// Element at the middle of the list.
		size_t mid = left + (right - left) / 2;

		// Splits the list until there are only individual elements in the list.
		MergeSortRecursion(list, left, mid);
		MergeSortRecursion(list, mid + 1, right);

		// After recursion is done, merge the sorted arrays.
		MergeSortedArrays(list, left, mid, right);
	}
}

template<typename T>
void List<T>::MergeSortedArrays(List<T>& list, size_t left, size_t mid, size_t right)
{
	// Length of left portion of list
	size_t LeftLength = mid - left + 1;
	// Length of left portion of list
	size_t RightLength = right - mid;

	// Temp arrays with same length as corresponding list
	T* TempLeft = new T[LeftLength];
	T* TempRight = new T[RightLength];
	
	size_t i, j, k;

	// Left sub array
	for (i = 0; i < LeftLength; i++)
		TempLeft[i] = list[left + i];

	// Right sub array
	for (i = 0; i < RightLength; i++)
		TempRight[i] = list[mid + 1 + i];
	
	//				i
	// TempLeft: 4, 9 ,12.
	//			  j
	// TempRight: 5, 8, 14.
	//
	// i keeps track of elements in the left sub array.
	// j keeps track of elements in the right sub array.
	// here TempR[j] = 5 < TempL[i] = 9
	// 5 will be added to list[k]
	// we increment j and k (i++, k++).
	for (i = 0, j = 0, k = left; k <= right; k++)
	{
		if ((i < LeftLength) &&
			(j >= RightLength || TempLeft[i] <= TempRight[j]))
		{
			// add element from TempLeft
			list[k] = TempLeft[i];
			// increment i.
			i++;
		}
		else
		{
			// add element from TempRight
			list[k] = TempRight[j];
			//increment j.
			j++;
		}
	}
}

template<typename T>
void List<T>::QuickSort(List<T>& list)
{
	std::cout << "Attempting quicksort." << std::endl;
	std::cout << "Sorting..." << std::endl;

	// for random numbers using time
	srand(time(NULL));

	// Pass in linked list, with the first and last element
	QuickSortRecursion(list, 0, NumberOfElements - 1);
}

template<typename T>
void List<T>::QuickSortRecursion(List<T>& list, int low, int high)
{
	// low = starting index, high = ending index
	if (low < high) // low >= high means we are done sorting
	{
		int PivotIndex = QuickSortPartition(list, low, high);
		// Left portion of list up until Pivot index - 1
		QuickSortRecursion(list, low, PivotIndex - 1);
		// Right portion of the array.
		QuickSortRecursion(list, PivotIndex + 1, high);
	}
}

template<typename T>
int List<T>::QuickSortPartition(List<T>& list, int low, int high)
{
	// pick a random index between high and low.
	int PivotIndex = low + (rand() % (high - low));

	// If PI != high, swap high and PI
	if (PivotIndex != high)
	{
		SwapNodes(list[PivotIndex], list[high]);
	}

	// value at list[high]
	T PivotValue = list[high];
	int i = low;
	
	for (int j = low; j < high; j++)
	{
		if (list[j] <= PivotValue)
		{
			//Swap nodes at list[i] and list[j].
			SwapNodes(list[i], list[j]);
			i++;

			// EXAMPLE:
			// Here j < i, we swap i and j, increment i by 1
			//   j
			// 6 3 7 5 1 2 [4] ; Pivot value = 4
			// i

			// increment j++ continue process until j < i
			//         j							        j
			// 3 6 7 5 1 2 [4] --> swap i and j --> 3 1 7 5 6 2 [4]
			//   i								      i

			// ending list
			//				j
			// 3 1 2 5 6 7 [4]
			//       i
		}
	}
	SwapNodes(list[i], list[high]);
	// Swap i and j
	//				j
	// 3 1 2 4 6 7 [5]
	//       i
	return i; // list[i] = 4 becomes Pivot index
}

template<typename T>
void List<T>::HeapSort(List<T>& list)
{
	int length = NumberOfElements;
	std::cout << "Attempting heapsort." << std::endl;
	std::cout << "Sorting..." << std::endl;

	// Creates a max heap.
	// A max heap is a complete binary tree in which the value of a node
	// is greater than or equal to the values of its children
	for (int i = length / 2 - 1; i >= 0; i--)
		Heapify(list, length, i);

	// Swaps first and last node.
	for (int i = length - 1; i > 0; i--)
	{
		SwapNodes(list[0], list[i]);
		Heapify(list, i, 0);
	}
}

template<typename T>

void List<T>::Heapify(List<T>& list, int length, int i)
{
	// i = root
	// find larges value among the root, left and right child
	int Largest = i;
	int Left = 2 * i + 1;
	int Right = 2 * i + 2;

	// if left is the largest
	if (Left < length && list[Left] > list[Largest])
		Largest = Left;

	// if right is the largest
	if (Right < length && list[Right] > list[Largest])
		Largest = Right;

	// if root is not largest swap root with the largest
	if (Largest != i) 
	{
		// Recursively heapify the sub-tree
		SwapNodes(list[i], list[Largest]);
		Heapify(list, length, Largest);
	}
}

template <typename T>
void List<T>::SwapNodes(T left, T right)
{
	// Exit early if left and right hold the same value.
	if (left == right) return;
 
	// Search for node holding value = "left" in the list.
	Node<T>* PrevLeft = nullptr;
	Node<T>* CurrentLeft = Head;
	while (CurrentLeft && CurrentLeft->Data != left)
	{
		PrevLeft = CurrentLeft;
		CurrentLeft = CurrentLeft->Next;
	}
 
	// Search for node holding value = "right" in the list.
	Node<T>* PrevRight = NULL;
	Node<T>* CurrentRight = Head;
	while (CurrentRight && CurrentRight->Data != right)
	{
		PrevRight = CurrentRight;
		CurrentRight = CurrentRight->Next;
	}
 
	// If either value was not found in the list, exit function.
	if (CurrentLeft == nullptr || CurrentRight  == nullptr) return;
 
	// If "right" is not the head of the linked list.
	if (PrevLeft != nullptr) PrevLeft->Next = CurrentRight;
	// Else make "right" as new head.
	else Head = CurrentRight;
 
	// If "left" is not head of linked list
	if (PrevRight != nullptr) PrevRight->Next = CurrentLeft;
	// Else make "left" as new head.
	else Head = CurrentLeft;
 
	// Swap next pointers
	Node<T>* Temp = CurrentRight->Next;
	CurrentRight->Next = CurrentLeft->Next;
	CurrentLeft->Next = Temp;
}