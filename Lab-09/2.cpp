// IMPLIMENTATION OF BINARY SEARCH TREE

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};
class BST
{
private:
    Node *root;

    void inorderHelper(Node *node)
    {
        if (node == NULL)
            return;
        inorderHelper(node->left);
        cout << node->data << " ";
        inorderHelper(node->right);
    }
    void preorderHelper(Node *node)
    {
        if (node == NULL)
            return;
        cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

public:
    BST() : root(NULL) {}
    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (root == NULL)
        {
            root = newNode;
            return;
        }
        Node *current = root;
        Node *parent = NULL;
        while (current != NULL)
        {
            parent = current;
            if (val < current->data)
            {
                current = current->left;
            }
            else if (val > current->data)
            {
                current = current->right;
            }
            else
            {

                return;
            }
        }
        if (val < parent->data)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }
    }

    void inorderTraversal()
    {
        cout << "In-order Traversal: ";
        inorderHelper(root);
        cout << endl;
    }
    void preorderTraversal()
    {
        cout << "Pre-order Traversal: ";
        preorderHelper(root);
        cout << endl;
    }
};

int main()
{
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.inorderTraversal();
    tree.preorderTraversal();
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    tree.inorderTraversal();
    tree.preorderTraversal();

    return 0;
}