#include <iostream>

#include "Node.h"
#include "List.h"


int main()
{
    List<std::string>* Slink = new List<std::string>();
    Slink->AddToTail("Sara");
    Slink->AddToTail("Carl");
    Slink->AddToTail("Jack");
    Slink->AddToTail("Steven");
    Slink->AddToTail("Rose");
    Slink->AddToTail("John");
    Slink->RemoveAtHead();
    Slink->PrintData();
    Slink->RemoveAt(3);
    Slink->PrintData();
    Slink->InsertAt(3, "Carl");
    Slink->AddToHead("George");
    Slink->RemoveAtTail();
    Slink->PrintData();
    std::cout << "Number of elements in list: " << Slink->GetNumberOfElements() << "." << std::endl;
    Slink->InsertAt(1, "John");
    Slink->PrintData();
    Slink->InsertAt(0, "Dennis");
    Slink->PrintData();
    std::cout << "Number of elements: " << Slink->GetNumberOfElements() << std::endl;
    
    //List<int>* int_link = new List<int>{1,163,835,734,4};
    List<int> int_link;

    int_link.AddToTail(6);
    int_link.AddToTail(12);
    int_link.AddToTail(30);
    int_link.AddToTail(1);
    int_link.AddToTail(4);
    int_link.AddToTail(23);
    
    int_link.PrintData();
    
    int_link.SelectionSort(int_link);
    std::cout << "Printing list after sorting: " << std::endl;
    int_link.PrintData();
    

    
    return 0;

}
