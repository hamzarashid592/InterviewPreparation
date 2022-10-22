#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *addNodeBST(Node *bst, int value)
{
    // Base case
    if (bst == NULL)
    {
        Node *newNode = new Node;

        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // Recursive calls.

    if (value > bst->data)
        bst->right = addNodeBST(bst->right, value);

    else if (value <= bst->data)
        bst->left = addNodeBST(bst->left, value);

    return bst;
}

void printTreeInOrder(Node *tree)
{
    // Base case.
    if (tree == NULL)
        return;

    // Recursive Call.
    printTreeInOrder(tree->left);
    cout << tree->data << "\t";

    printTreeInOrder(tree->right);
}

void printTreePostOrder(Node *tree)
{
    // Base case.
    if (tree == NULL)
        return;

    // Recursive Call.
    printTreePostOrder(tree->left);
    printTreePostOrder(tree->right);

    cout << tree->data << "\t";
}

Node *getMaxInBST(Node *tree)
{
    // Base case.
    if (tree->right == NULL)
        return tree;

    // Recursive Call.
    return getMaxInBST(tree->right);
}

Node *getMinInBST(Node *tree)
{
    // Base case.
    if (tree->left == NULL)
        return tree;

    // Recursive Call.
    return getMinInBST(tree->left);
}

Node *deleteNodeFromBST(Node *tree, int value)
{
    // Base case
    if (tree == NULL)
        return NULL;

    // Recursive Calls.
    if (value > tree->data)
    {
        tree->right = deleteNodeFromBST(tree->right, value);
    }
    else if (value < tree->data)
    {
        tree->left = deleteNodeFromBST(tree->left, value);
    }

    // Got the data.
    if (value == tree->data)
    {
        // Childless node.
        if (tree->left == NULL && tree->right == NULL)
        {
            delete tree;
            tree = NULL; // To avoid an error while returning.
        }
        // Left child node.
        if (tree->left != NULL)
        {
            Node *temp = tree;
            tree = tree->left; // Replacing the node with its single child.
            delete temp;
        }
        // Right child node.
        if (tree->right != NULL)
        {
            Node *temp = tree;
            tree = tree->right; // Replacing the node with its single child.
            delete temp;
        }
        // Two children node.
        if (tree->right != NULL && tree->left != NULL)
        {
            // Getting the max in the left subtree.
            Node *maxNode = getMaxInBST(tree->left);
            // Replacing the data of the current node with that max node.
            tree->data = maxNode->data;
            // Deleting that max node.
            tree->left = deleteNodeFromBST(tree->left, maxNode->data);
        }
    }

    return tree;
}

int main()
{
    Node *tree = NULL;

    tree = addNodeBST(tree, 4);
    tree = addNodeBST(tree, 15);
    tree = addNodeBST(tree, 14);
    tree = addNodeBST(tree, 2);
    tree = addNodeBST(tree, 18);
    tree = addNodeBST(tree, 1);
    tree = addNodeBST(tree, 17);
    tree = addNodeBST(tree, 3);
    tree = addNodeBST(tree, 9);
    tree = addNodeBST(tree, 7);
    tree = addNodeBST(tree, 8);
    tree = addNodeBST(tree, 19);
    tree = addNodeBST(tree, 10);
    tree = addNodeBST(tree, 16);
    tree = addNodeBST(tree, 5);
    tree = addNodeBST(tree, 12);
    tree = addNodeBST(tree, 11);
    tree = addNodeBST(tree, 20);
    tree = addNodeBST(tree, 6);

    printTreeInOrder(tree);

    cout << endl;

    cout << getMaxInBST(tree)->data << endl;
    cout << getMinInBST(tree)->data << endl;

    tree = deleteNodeFromBST(tree, 1);
    printTreeInOrder(tree);

    return 0;
}