#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TreeNode {
public:
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

TreeNode* constructTreeFromPrefix(string prefix) {
    stack<TreeNode*> st;

    for (int i = prefix.size() - 1; i >= 0; i--) {
        char c = prefix[i];
        TreeNode* newNode = new TreeNode(c);

        if (!isOperator(c)) {
            st.push(newNode);
        } else {
            newNode->left = st.top();
            st.pop();
            newNode->right = st.top();
            st.pop();
            st.push(newNode);
        }
    }

    return st.top();
}

TreeNode* constructTreeFromPostfix(string postfix) {
    stack<TreeNode*> st;

    for (char c : postfix) {
        TreeNode* newNode = new TreeNode(c);

        if (!isOperator(c)) {
            st.push(newNode);
        } else {
            newNode->right = st.top();
            st.pop();
            newNode->left = st.top();
            st.pop();
            st.push(newNode);
        }
    }

    return st.top();
}

void recursiveInOrder(TreeNode* root) {
    if (root) {
        recursiveInOrder(root->left);
        cout << root->data << " ";
        recursiveInOrder(root->right);
    }
}

void nonRecursiveInOrder(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* current = root;

    while (current || !st.empty()) {
        while (current) {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

void recursivePreOrder(TreeNode* root) {
    if (root) {
        cout << root->data << " ";
        recursivePreOrder(root->left);
        recursivePreOrder(root->right);
    }
}

void nonRecursivePreOrder(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* current = st.top();
        st.pop();
        cout << current->data << " ";
        if (current->right) st.push(current->right);
        if (current->left) st.push(current->left);
    }
}

void recursivePostOrder(TreeNode* root) {
    if (root) {
        recursivePostOrder(root->left);
        recursivePostOrder(root->right);
        cout << root->data << " ";
    }
}

void nonRecursivePostOrder(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> st;
    stack<TreeNode*> output;
    st.push(root);

    while (!st.empty()) {
        TreeNode* current = st.top();
        st.pop();
        output.push(current);
        if (current->left) st.push(current->left);
        if (current->right) st.push(current->right);
    }

    while (!output.empty()) {
        cout << output.top()->data << " ";
        output.pop();
    }
}

int main() {
    cout << "Enter your choice \n";
    cout<<"1. Construct the binary tree using prefix expression. \n";
    cout<<"2. Construct the binary tree using postfix expression. \n";
    cout<<"0. Exit" << endl;

    int choice;
    cin >> choice;

    TreeNode* root = nullptr;
    switch (choice) {
        case 1: {
            string prefixExpression;
            cout << "Enter a prefix expression: ";
            cin >> prefixExpression;
            root = constructTreeFromPrefix(prefixExpression);
            break;
        }
        case 2: {
            string postfixExpression;
            cout << "Enter a postfix expression: ";
            cin >> postfixExpression;
            root = constructTreeFromPostfix(postfixExpression);
            break;
        }
        default:
            cout << "Invalid choice" << endl;
            break;
    }
    cout << "Which operation do you want to perform? \n1. In-order recursive \n2. Pre-order recursive \n3. Post-order recursive \n4. In-order non-recursive \n5. Pre-order non-recursive \n6. Post-order non-recursive \n0.exit" << endl;
    int operation;
    cin >> operation;
    while(operation!=0){        
        if (root) {
            switch (operation) {
                case 1:
                    cout << "In-order traversal: ";
                    recursiveInOrder(root);
                    cout << endl;
                    break;
                case 2:
                    cout << "Pre-order traversal: ";
                    recursivePreOrder(root);
                    cout << endl;
                    break;
                case 3:
                    cout << "Post-order traversal: ";
                    recursivePostOrder(root);
                    cout << endl;
                    break;
                case 4:
                    cout << "In-order non-recursive traversal: ";
                    nonRecursiveInOrder(root);
                    cout << endl;
                    break;
                case 5:
                    cout << "Pre-order non-recursive traversal: ";
                    nonRecursivePreOrder(root);
                    cout << endl;
                    break;
                case 6:
                    cout << "Post-order non-recursive traversal: ";
                    nonRecursivePostOrder(root);
                    cout << endl;
                    break;
                default:
                    cout << "Invalid choice" << endl;
                    break;
            }
        }
        cout << "Which operation do you want to perform? \n1. In-order recursive \n2. Pre-order recursive \n3. Post-order recursive \n4. In-order non-recursive \n5. Pre-order non-recursive \n6. Post-order non-recursive  \n0.exit" << endl;
        cin >> operation;
    }

    return 0;
}
