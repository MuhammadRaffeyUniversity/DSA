// BINARY TREE IMPLEMENTATION WITH INSERTION, DELETION, DISPLAY AND SEARCHING USING BFS AND DFS

#include <iostream>
using namespace std;
#include <queue>
#include <stack>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
{
private:
    Node *root;

public:
    BinaryTree()
    {
        root = NULL;
    }

    void insert(int val)
    {
        Node *newnode = new Node(val);
        if (root == NULL)
        {
            root = newnode;
            return;
        }
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (!temp->left)
            {
                temp->left = newnode;
                return;
            }
            else
            {
                q.push(temp->left);
            }
            if (!temp->right)
            {
                temp->right = newnode;
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }
    }

    void display()
    {
        if (root == NULL)
        {
            cout << "Empty tree! ";
            return;
        }
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }

    void deleteDeepest(Node *root, Node *delNode)
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left)
            {
                if (temp->left == delNode)
                {
                    delete temp->left;
                    temp->left = NULL;
                    return;
                }
                q.push(temp->left);
            }

            if (temp->right)
            {
                if (temp->right == delNode)
                {
                    delete temp->right;
                    temp->right = NULL;
                    return;
                }
                q.push(temp->right);
            }
        }
    }

    void delNode(int val)
    {
        if (root == NULL)
        {
            cout << "Empty tree";
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            if (root->data == val)
            {
                delete root;
                root = NULL;
            }
            return;
        }
        queue<Node *> q;
        q.push(root);

        Node *target = NULL;
        Node *last = NULL;
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (temp->data == val)
                target = temp;

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);

            last = temp;
        }
        if (target)
        {
            int x = last->data;
            deleteDeepest(root, last);
            target->data = x;
        }
    }

    bool BFS(int val)
    {
        if (root == NULL)
        {
            return false;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (temp->data == val)
            {
                return true;
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        return false;
    }

    bool DFSpreorder(int val)
    {
        if (root == NULL)
        {
            return false;
        }
        stack<Node *> s;
        s.push(root);
        while (!s.empty())
        {
            Node *temp = s.top();
            s.pop();
            if (temp->data == val)
            {
                return true;
            }
            if (temp->right)
            {
                s.push(temp->right);
            }
            if (temp->left)
            {
                s.push(temp->left);
            }
        }
        return false;
    }

    bool InorderDFS(int val)
    {
        if (root == NULL)
        {
            return false;
        }

        stack<Node *> s;
        Node *temp = root;

        while (temp != NULL || !s.empty())
        {
            while (temp != NULL)
            {
                s.push(temp);
                temp = temp->left;
            }
            Node *temp = s.top();
            s.pop();
            if (temp->data == val)
            {
                return true;
            }
            temp = temp->right;
        }
        return false;
    }

    bool DFSpostorder(int val)
    {
        if (root == NULL)
        {
            cout << "Empty tree";
            return false;
        }
        stack<Node *> s1;
        stack<Node *> s2;
        Node *temp = root;
        s1.push(temp);
        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            s2.push(temp);
            if (temp->left)
            {
                s1.push(temp->left);
            }
            if (temp->right)
            {
                s1.push(temp->right);
            }
        }
        while (!s2.empty())
        {
            Node *temp = s2.top();
            s2.pop();
            if (temp->data == val)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    BinaryTree bt;
    bt.insert(10);
    bt.insert(20);
    bt.insert(30);
    bt.insert(40);
    bt.display();
    bt.delNode(30);
    cout << endl;
    bt.display();
    cout << endl;
    cout << bt.BFS(20);
    cout << endl;
    cout << bt.DFSpreorder(20);
    cout << endl;
    cout << bt.InorderDFS(10);
    cout << endl;
    cout << bt.DFSpostorder(40);

    return 0;
}
