#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
        root->right = insertIntoBST(root->right, d);
    else
        root->left = insertIntoBST(root->left, d);

    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
    return;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int max(Node *root)
{
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int min(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

Node *deleteFromBST(Node *root, int x)
{
    // base case
    if (root == NULL)
        return NULL;

    if (root->data == x)
    {

        // leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // single left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // single right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // node with 2 children
        else
        {
            int mini = min(root->right);
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }

    else
    {
        if (x > root->data)
            root->right = deleteFromBST(root->right, x);
        else
            root->left = deleteFromBST(root->left, x);
    }
}

int findInorderSuccessor(Node *root, int key)
{
    int successor=-1;
    while (root)
    {
        if (key < root->data)
        {
            successor = root->data;
            root = root->left;
        }
        else if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            if (root->right)
            {
                successor = min(root->right);
            }
            break;
        }
    }

    return successor;
}

int findInorderPredecessor(Node *root, int key)
{
    int predecessor=-1;
    while (root)
    {
        if (key < root->data)
            root = root->left;

        else if (key > root->data)
        {
            predecessor = root->data;
            root = root->right;
        }

        else
        {
            if (root->left)
                predecessor = max(root->left);
            break;
        }
    }
    return predecessor;
}
int main()
{
    Node *root = NULL;

    // 8 3 10 1 6 14 4 7 13 -1
    cout << "Input the data to insert in BST: ";
    takeInput(root);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Max: " << max(root) << " "
         << "Min: " << min(root) << endl;

    int inorderSuccessor, inorderPredecessor;
    cout << "Node to find inorder successor: ";
    cin >> inorderSuccessor;
    cout << endl
         << "Inorder successor of " << inorderSuccessor << " is " << findInorderSuccessor(root, inorderSuccessor) << endl;

    cout<<"Node to find inorder predecessor: ";
    cin>>inorderPredecessor;
    cout<<endl<<"Inorder successor of "<<inorderPredecessor<<" is "<<findInorderPredecessor(root,inorderPredecessor)<<endl;;

    int nodeToDelete;
    cout << "Enter node to delete: ";
    cin >> nodeToDelete;

    deleteFromBST(root, nodeToDelete);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    return 0;
}