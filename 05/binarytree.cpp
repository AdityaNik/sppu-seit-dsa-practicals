// Name= Aditya Nikam
// Branch = SE-IT  Batch = S4
// Roll No = 3098

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Binary
{
public:
    node *insert(node *root, int value)
    {
        if (root == NULL)
        {
            return new node(value);
        }

        if (value < root->data)
        {
            root->left = insert(root->left, value);
        }
        else
        {
            root->right = insert(root->right, value);
        }
        return root;
    }

    node *findMin(node *root)
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root;
    }

    node *Delete(node *root, int value)
    {
        if (root == NULL){
            return NULL;
        }
        if (value < root->data){
            root->left = Delete(root->left, value);
        }
        else if (value > root->data){
            root->right = Delete(root->right, value);
        }
        else{
            if (root->left == NULL){
                node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL){
                node *temp = root->left;
                delete root;
                return temp;
            }

            node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
        return root;
    }

    bool search(node *root, int key){
        if (root == NULL){
            return false;
        }
        if (root->data == key){
            return true;
        }
        else if (key < root->data){
            return (search(root->left, key));
        }
        else{
            return (search(root->right, key));
        }
    }

    void inorder(node *root){
        if (root != NULL){
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    node *copyTree(node *root){
        if (root == NULL){
            return NULL;
        }

        node *copyNode = new node(root->data);
        copyNode->left = copyTree(root->left);
        copyNode->right = copyTree(root->right);

        return copyNode;
    }

    node* Mirrorimage(node *root){
        if (root != NULL){
            node * mirrornode = new node(root->data);
            mirrornode->left = Mirrorimage(root->right);
            mirrornode->right = Mirrorimage(root->left);

            return mirrornode;
        }
        return NULL;
    }

    int TreeDepth(node *root){
        if (root == nullptr){
            return 0;
        }

        int leftDepth = TreeDepth(root->left);
        int rightDepth = TreeDepth(root->right);

        return max(leftDepth, rightDepth) + 1;
    }
};

int main(){
    Binary bt;
    node *root = NULL;
    root = bt.insert(root, 5);
    bt.insert(root, 6);
    bt.insert(root, 4);
    bt.insert(root, 3);
    bt.insert(root, 30);
    bt.insert(root, 14);

    cout << "inorder display: ";
    bt.inorder(root);
    cout << endl;
    cout << "-----------------------------" << endl;
    cout << "Enter element for search:" << endl;
    int key;
    cin >> key;
    cout << "Search for " << key << ": " << (bt.search(root, key) ? "found" : "not found") << endl;
    cout << endl;
    cout << "-----------------------------" << endl;
    cout << "Enter element to delete:";
    int val;
    cin >> val;
    bt.Delete(root, val);
    cout << endl;
    cout << "Inorder display after deletion: ";
    bt.inorder(root);
    cout << endl;
    cout << "-----------------------------" << endl;
    int depth = bt.TreeDepth(root);
    cout << "Depth of the tree: " << depth << endl;
    cout << endl;
    cout << "-----------------------------" << endl;
    node *copiedRoot = bt.copyTree(root);
    cout << "Copy of the tree - Inorder display: ";
    bt.inorder(copiedRoot);
    cout << endl;
    cout << "-----------------------------" << endl;
    node* image = bt.Mirrorimage(root);
    cout << "Mirror copy - inorder display: ";
    bt.inorder(image);
    cout << endl;
    cout << "-----------------------------" << endl;
    return 0;
}