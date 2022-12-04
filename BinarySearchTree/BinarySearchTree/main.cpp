#include <iostream>

#include "Node.h"
#include "BinaryTree.h"

const int Size = 16;

int input = 0;

int main()
{
    // for (int i = 0; i < Size; i++)
    // {
    //     int num = 1+ (rand() % 100);
    //     arr[i] = num;
    // }

    int arr[Size] = {25,12,44,51,3,56,8,9,11,23,91,38,2,6,1,26};
    
    BinaryTree<int>* Tree = new BinaryTree<int>();

    std::cout << "Printing the tree in order" << std::endl;
    std::cout << "Before adding numbers" << std::endl;
    Tree->PrintInOrder();

    for (int i = 0; i < Size -1 ; i++)
    {
        Tree->AddLeaf(arr[i]);
    }

    std::cout << "Printing the tree in order" << std::endl;
    std::cout << "After adding numbers" << std::endl;

    Tree->PrintInOrder();

    std::cout<<std::endl;
    std::cout << std::endl;

    std::cout << "Printing the tree pre order" << std::endl;
    Tree->PrintPreOrder();

    std::cout<<std::endl;
    std::cout << std::endl;

    std::cout << "Printing the tree post order" << std::endl;
    Tree->PrintPostOrder();

    std::cout<<std::endl;
    std::cout << std::endl;


    // for (int i = 0; i < Size; i++)
    // {
    //     Tree->PrintChildren(arr[i]);
    //     std::cout << std::endl;
    // }

    std::cout << "The smallest node in the tree is " << Tree->FindSmallest() << std::endl;
    std::cout << std::endl;
    std::cout << "Enter a key value to delete. Enter -1 to stop the process." << std::endl;
    
    while (input != -1)
    {
        std::cout << "Delete Node: " << std::endl;
        std::cin >> input;
        {
            if (input != -1)
            {
                std::cout << std::endl;
                Tree->RemoveNode(input);
                Tree->PrintInOrder();
                std::cout << std::endl;
            }
        }
    }
    Tree->RemoveSubtree();
    
    return 0;
}
