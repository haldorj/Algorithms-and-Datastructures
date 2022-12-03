#include <iostream>
#include <string>
#include <sstream>

#include "Node.h"
#include "List.h"


int main()
{
    // List<std::string>* Slink = new List<std::string>();
    // List<std::string> Slink;
    // Slink.AddToTail("Sara");
    // Slink.AddToTail("Carl");
    // Slink.AddToTail("Jack");
    // Slink.AddToTail("Steven");
    // Slink.AddToTail("Rose");
    // Slink.AddToTail("John");
    // Slink.PrintData();
    // Slink.RemoveAtHead();
    // Slink.PrintData();
    // Slink.RemoveAt(2);
    // Slink.PrintData();
    // Slink.InsertAt(3, "Karen");
    // Slink.AddToHead("George");
    // Slink.RemoveAtTail();
    // Slink.PrintData();
    // std::cout << "Number of elements in list: " << Slink.GetNumberOfElements() << "." << std::endl;
    // Slink.InsertAt(1, "John");
    // Slink.PrintData();
    // Slink.InsertAt(0, "Dennis");
    // Slink.PrintData();
    // std::cout << "Number of elements: " << Slink.GetNumberOfElements() << std::endl;
    //
    // //Slink.SelectionSort(Slink);
    // //Slink.BubbleSort(Slink);
    // //Slink.MergeSort(Slink);
    // Slink.QuickSort(Slink);
    // //Slink.HeapSort(Slink);
    //
    // std::cout << "Printing list after sorting: " << std::endl;
    // Slink.PrintData();
    
    List<int> int_link;
    int_link.AddToTail(6);
    int_link.AddToTail(12);
    int_link.AddToTail(30);
    int_link.AddToTail(1);
    int_link.AddToTail(4);
    int_link.AddToTail(23);
    int_link.PrintData();
    //int_link.SelectionSort(int_link);
    //int_link.BubbleSort(int_link);
    //int_link.MergeSort(int_link);
    int_link.QuickSort(int_link);
    //int_link.HeapSort(int_link);
    std::cout << "Printing list after sorting: " << std::endl;
    int_link.PrintData();

    List<char> char_link;
    char_link.AddToTail('C');
    char_link.AddToTail('X');
    char_link.AddToTail('E');
    char_link.AddToTail('B');
    char_link.AddToTail('A');
    char_link.AddToTail('W');
    
    char_link.PrintData();
    
    //char_link.SelectionSort(char_link);
    //char_link.BubbleSort(char_link);
    //char_link.MergeSort(char_link);
    char_link.QuickSort(char_link);
    //char_link.HeapSort(char_link);
    std::cout << "Printing list after sorting: " << std::endl;
    char_link.PrintData();
    
    char_link.LinearSearch(char_link, 'E');
    char_link.LinearSearch(char_link, 'C');
    char_link.BinarySearch(char_link,'W');
    

    

    
    return 0;

}
