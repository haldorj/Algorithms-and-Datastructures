#pragma once

template<typename T>
class BinaryTree : public Node<T>
{
public:
    BinaryTree();
    ~BinaryTree();
    void AddLeaf(T value);
    void PrintInOrder();
    void PrintPreOrder();
    void PrintPostOrder();
    T ReturnRootValue();
    void PrintChildren(T value);
    T FindSmallest();
    void RemoveNode(T value);
    void RemoveSubtree();
    
private:
    Node<T>* Root; // The node at the very top of the tree.
    Node<T>* CreateLeaf(T value);
    Node<T>* ReturnNode(T value);
    void AddLeafPrivate(T value, Node<T>* ptr);
    void PrintInOrderPrivate(Node<T>* ptr); // Function to perform inorder traversal on the tree (1. Go left, 2. Process Current Node, 3. Go right.)
    void PrintPreOrderPrivate(Node<T>* ptr);
    void PrintPostOrderPrivate(Node<T>* ptr);
    Node<T>* ReturnNodePrivate(T value, Node<T>* ptr); // Finds a specific node in the tree.
    T FindSmallestPrivate(Node<T>* ptr);
    void RemoveNodePrivate(T value, Node<T>* parent);
    void RemoveRootMatch();
    void RemoveMatch(Node<T>* parent, Node<T>* match, bool left);
    void RemoveSubtreePrivate(Node<T>* ptr);
    T MatchKey;
};

template <typename T>
BinaryTree<T>::BinaryTree()
{
    Root = nullptr;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    RemoveSubtree();
}

template <typename T>
Node<T>* BinaryTree<T>::CreateLeaf(T value)
{
    Node<T>* newNode = new Node<T>;
    if (newNode)
    {
        newNode->Data = value;
        newNode->Left = nullptr;
        newNode->Right = nullptr;
    }

    return  newNode;
}

template <typename T>
void BinaryTree<T>::AddLeaf(T value)
{
    AddLeafPrivate(value, Root);
}

template <typename T>
void BinaryTree<T>::AddLeafPrivate(T value, Node<T>* ptr)
{
    if (Root == nullptr)
    {
        Root = CreateLeaf(value);
    }
    else if (value < ptr->Data)
    {
        if(ptr->Left != nullptr)
        {
            AddLeafPrivate(value, ptr->Left);
        }
        else
        {
            ptr->Left = CreateLeaf(value);
        }
    }
    else if (value > ptr->Data)
    {
        if(ptr->Right != nullptr)
        {
            AddLeafPrivate(value, ptr->Right);
        }
        else
        {
            ptr->Right = CreateLeaf(value);
        }
    }
    else
    {
        std::cout << "The key " << value << "has already been added to the tree." << std::endl;
    }
}

template <typename T>
void BinaryTree<T>::PrintInOrder()
{
    PrintInOrderPrivate(Root);
}

template <typename T>
void BinaryTree<T>::PrintPreOrder()
{
    PrintPreOrderPrivate(Root);
}

template <typename T>
void BinaryTree<T>::PrintPostOrder()
{
    PrintPostOrderPrivate(Root);
}

template <typename T>
void BinaryTree<T>::PrintInOrderPrivate(Node<T>* ptr)
{
    if (Root != nullptr)
    {
        if(ptr->Left != nullptr)
        {
            PrintInOrderPrivate(ptr->Left);
        }
        std::cout << ptr->Data << " ";
        if(ptr->Right != nullptr)
        {
            PrintInOrderPrivate(ptr->Right);
        }
    }
    else
    {
        std::cout << "The Tree is empty!" << std::endl;
    }
}

template <typename T>
void BinaryTree<T>::PrintPreOrderPrivate(Node<T>* ptr)
{
    if (Root != nullptr)
    {
        std::cout << ptr->Data << " ";
        if(ptr->Left != nullptr)
        {
            PrintPreOrderPrivate(ptr->Left);
        }
        if(ptr->Right != nullptr)
        {
            PrintPreOrderPrivate(ptr->Right);
        }
    }
    else
    {
        std::cout << "The Tree is empty!" << std::endl;
    }
}

template <typename T>
void BinaryTree<T>::PrintPostOrderPrivate(Node<T>* ptr)
{
    if (Root != nullptr)
    {
        if(ptr->Left != nullptr)
        {
            PrintPostOrderPrivate(ptr->Left);
        }
        if(ptr->Right != nullptr)
        {
            PrintPostOrderPrivate(ptr->Right);
        }
        std::cout << ptr->Data << " ";
    }
    else
    {
        std::cout << "The Tree is empty!" << std::endl;
    }
}

template <typename T>
Node<T>* BinaryTree<T>::ReturnNode(T value)
{
    return ReturnNodePrivate(value, Root);
}

template <typename T>
Node<T>* BinaryTree<T>::ReturnNodePrivate(T value, Node<T>* ptr)
{
    if (ptr != nullptr)
    {
        if(ptr->Data == value)
        {
            return ptr;
        }
        else
        {
            if (value < ptr->Data)
            {
                return ReturnNodePrivate(value, ptr->Left);
            }
            else
            {
                return ReturnNodePrivate(value, ptr->Right);
            }
        }
    }
    else
    {
        return nullptr;
    }
}

template <typename T>
T BinaryTree<T>::ReturnRootValue()
{
    if (Root != nullptr)
    {
        return Root->Data;
    }
    else
    {
        std::cout << "There is no root." << std::endl;
        return 0;
    }
}

template <typename T>
void BinaryTree<T>::PrintChildren(T value)
{
    Node<T>* ptr = ReturnNode(value);

    if (ptr != nullptr)
    {
        std::cout << "Parent Node = " << ptr->Data << std::endl;

        ptr->Left == nullptr ?
            std::cout << "Left child = nullptr " << std::endl :
            std::cout << "Left child = " << ptr->Left->Data << std::endl;

        ptr->Right == nullptr ?
            std::cout << "Right child = nullptr " << std::endl :
            std::cout << "Right child = " << ptr->Right->Data << std::endl;
    }
    else
    {
        std::cout << "Value " << value << " is not in the tree." << std::endl;
    }
}

template <typename T>
T BinaryTree<T>::FindSmallest()
{
    return FindSmallestPrivate(Root);
}

template <typename T>
T BinaryTree<T>::FindSmallestPrivate(Node<T>* ptr)
{
    if (Root == nullptr)
    {
        std::cout << "Tree is empty." << std::endl;
        return -1000;
    }
    else
    {
        if (ptr->Left != nullptr)
        {
            return FindSmallestPrivate(ptr->Left);
        }
        else
        {
            return ptr->Data;
        }
    }
}

template <typename T>
void BinaryTree<T>::RemoveNode(T value)
{
    MatchKey = value;
    RemoveNodePrivate(value, Root);
}

template <typename T>
void BinaryTree<T>::RemoveNodePrivate(T value, Node<T>* parent)
{
    if (Root != nullptr)
    {
        if (Root->Data == value)
        {
            RemoveRootMatch();
        }
        else
        {
            if (value < parent->Data && parent->Left != nullptr)
            {
                // if left child contains value we're trying to delete
                parent->Left->Data == value ?
                RemoveMatch(parent, parent->Left, true) :
                RemoveNodePrivate(value, parent->Left);
            }
            else if (value > parent->Data && parent->Right != nullptr)
            {
                // if right child contains value we're trying to delete
                parent->Right->Data == value ?
                RemoveMatch(parent, parent->Right, false) :
                RemoveNodePrivate(value, parent->Right);
            }
            else
            {
                std::cout << "The value " << value << " was not found in the tree." << std::endl;
            }
        }
    }
    else
    {
        std::cout << "The tree is empty. " << std::endl;
    }
}

template <typename T>
void BinaryTree<T>::RemoveRootMatch()
{
    if(Root != nullptr)
    {
        Node<T>* delPtr = Root;
        T RootValue = Root->Data;
        T SmallestInRightSubtree;

        // Case 0 - Root has 0 children
        if (Root->Left == nullptr && Root->Right == nullptr)
        {
            Root = nullptr;
            delete delPtr;
        }

        // Case 1 - Root has 1 child
        // Right
        else if (Root->Left == nullptr && Root->Right != nullptr)
        {
            Root = Root->Right;
            delPtr->Right = nullptr;
            delete delPtr;
            std::cout << "The root node with value " << RootValue << " was deleted ";
            std::cout << "The new root contains value " << Root->Data << "." << std::endl;
        }
        // Left
        else if (Root->Left != nullptr && Root->Right == nullptr)
        {
            Root = Root->Left;
            delPtr->Left = nullptr;
            delete delPtr;
            std::cout << "The root node with value " << RootValue << " was deleted ";
            std::cout << "The new root contains value " << Root->Data << "." << std::endl;
        }

        // Case 2 - 2 children
        else
        {
            {
                SmallestInRightSubtree = FindSmallestPrivate(Root->Right);
                RemoveNodePrivate(SmallestInRightSubtree, Root);
                Root->Data = SmallestInRightSubtree;
                std::cout << "The root containing value " << RootValue;
                std::cout << " was overwritten with key " << Root->Data << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Can not remove root. The tree is empty." << std::endl;
    }
}

template <typename T>
void BinaryTree<T>::RemoveMatch(Node<T>* parent, Node<T>* match, bool left)
{
    if (Root != nullptr)
    {
        Node<T>* delPtr;
        T SmallestInRightSubtree;

        // case 0 - 0 Children
        if (match->Left == nullptr && match->Right == nullptr)
        {
            delPtr = match;
            left == true ? parent->Left = nullptr : parent->Right = nullptr;
            delete delPtr;
            std::cout << "The node containing value " << MatchKey << " was removed" << std::endl; 
        }

        // case 1 - 1 Child
        // Right
        else if (match->Left == nullptr && match->Right != nullptr)
        {
            left == true ? parent->Left = match->Right : parent->Right = match->Right;
            match->Right = nullptr;
            delPtr = match;
            std::cout << "The node containing value " << MatchKey << " was removed" << std::endl; 
            delete delPtr;
        }
        // Left
        else if (match->Left != nullptr && match->Right == nullptr)
        {
            left == true ? parent->Left = match->Left : parent->Right = match->Left;
            match->Left = nullptr;
            delPtr = match;
            std::cout << "The node containing value " << MatchKey << " was removed" << std::endl; 
            delete delPtr;
        }
        // Case 2 - 2 children
        else
        {
            SmallestInRightSubtree = FindSmallestPrivate(match->Right);
            RemoveNodePrivate(SmallestInRightSubtree, match);
            match->Data = SmallestInRightSubtree;
        }
    }
    else
    {
        std::cout << "Can not remove match. The tree is empty " << std::endl;
    }
}

template <typename T>
void BinaryTree<T>::RemoveSubtree()
{
    RemoveSubtreePrivate(Root);
}

template <typename T>
void BinaryTree<T>::RemoveSubtreePrivate(Node<T>* ptr)
{
    if (ptr != nullptr)
    {
        if(ptr->Left != nullptr)
        {
            RemoveSubtreePrivate(ptr->Left);
        }
        if(ptr->Right != nullptr)
        {
            RemoveSubtreePrivate(ptr->Right);
        }
        std::cout << "Deleting the node containing " <<  ptr->Data << std::endl;
        delete ptr;
    }
}
