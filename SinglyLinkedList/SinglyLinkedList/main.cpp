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
    
    return 0;

}
