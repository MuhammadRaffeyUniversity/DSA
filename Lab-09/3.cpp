#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
    Node *root = nullptr;

public:
    void setRoot(int v)
    {
        if (!root)
            root = new Node(v);
        else
            root->data = v;
    }

    bool insert(int parentVal, int val)
    {
        if (!root)
            return false;

        Node *parent = nullptr;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp->data == parentVal)
            {
                parent = temp;
                break;
            }
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        if (!parent)
            return false;

        Node *newNode = new Node(val);
        queue<Node *> sub;
        sub.push(parent);

        while (!sub.empty())
        {
            Node *temp = sub.front();
            sub.pop();

            if (!temp->left)
            {
                temp->left = newNode;
                return true;
            }
            sub.push(temp->left);

            if (!temp->right)
            {
                temp->right = newNode;
                return true;
            }
            sub.push(temp->right);
        }

        return false;
    }
};

int main()
{
    BinaryTree bt;
    bt.setRoot(9);

    bt.insert(9, 5);
    bt.insert(9, 1);

    bt.insert(5, 4);
    bt.insert(5, 3);

    bt.insert(5, 6);
    bt.insert(5, 7);

    return 0;
}
