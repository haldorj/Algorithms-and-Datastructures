#pragma once

template<typename T>
struct Node
{
    T Data;
    Node* Right;
    Node* Left;

    Node()
    {
        Data = 0;
        Right = nullptr;
        Left = nullptr;
    }
};

// Nodes with a lower values are added to the left.
// Nodes with a higher value are added to the right.

//            8
//         /    \
//        3      10
//      /  \   /   \
//     1   6       14
//        / \     /
//       4   7   13

// The node at the very top of the tree is the "root".
// A given nodes "parent" node is the node above.
// A given nodes "child" node is the node below, left or right.
// A "leaf" is a node with no children.