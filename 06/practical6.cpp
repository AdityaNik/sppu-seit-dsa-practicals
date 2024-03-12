/*
 *   Name: Aditya Nikam
 *   Roll No: 3098
 *   Threaded Binary Tree
 */

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
    {
        if (root->left == NULL)
        {
            root->left = newNode(data);
            return root;
        }
        insert(root->left, data);
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = newNode(data);
            return root;
        }
        insert(root->right, data);
    }

    return root;
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    Node *root = NULL;
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        root = insert(root, val);
    }

    cout << "In-order traversal of the threaded binary tree is: ";
    inOrder(root);
    cout << endl;

    cout << "Pre-order traversal of the threaded binary tree is: ";
    preOrder(root);
    cout << endl;

    return 0;
}
