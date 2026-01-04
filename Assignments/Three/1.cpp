#include <iostream>
#include <queue>

using namespace std;

struct Node
{
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

Node *buildTreeFromArray(int arr[], int n)
{
    if (n <= 0)
    {
        return NULL;
    }

    Node **nodes = new Node *[n];
    for (int i = 0; i < n; i++)
    {
        nodes[i] = new Node(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;
        if (leftIndex < n)
        {
            nodes[i]->left = nodes[leftIndex];
        }
        if (rightIndex < n)
        {
            nodes[i]->right = nodes[rightIndex];
        }
    }

    Node *root = nodes[0];
    delete[] nodes;
    return root;
}

void printLevelOrder(Node *root)
{
    if (root == NULL)
    {
        cout << "Empty tree" << endl;
        return;
    }

    queue<Node *> q;
    q.push(root);
    bool first = true;
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        if (!first)
        {
            cout << " ";
        }
        first = false;
        cout << current->data;
        if (current->left)
        {
            q.push(current->left);
        }
        if (current->right)
        {
            q.push(current->right);
        }
    }
    cout << endl;
}

void collectUniqueLevelOrder(Node *root, int outArr[], int &outCount, int maxCount)
{
    outCount = 0;
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        bool alreadySeen = false;
        for (int i = 0; i < outCount; i++)
        {
            if (outArr[i] == current->data)
            {
                alreadySeen = true;
                break;
            }
        }

        if (!alreadySeen && outCount < maxCount)
        {
            outArr[outCount++] = current->data;
        }

        if (current->left)
        {
            q.push(current->left);
        }
        if (current->right)
        {
            q.push(current->right);
        }
    }
}

void simpleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

Node *buildBSTFromSorted(int arr[], int left, int right)
{
    if (left > right)
    {
        return NULL;
    }

    int mid = (left + right) / 2;
    Node *root = new Node(arr[mid]);
    root->left = buildBSTFromSorted(arr, left, mid - 1);
    root->right = buildBSTFromSorted(arr, mid + 1, right);
    return root;
}

void printInOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

void freeTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Invalid size" << endl;
        return 1;
    }

    int *values = new int[size];
    cout << "Enter " << size << " integer values: ";
    for (int i = 0; i < size; i++)
    {
        cin >> values[i];
    }

    Node *originalTree = buildTreeFromArray(values, size);
    cout << "Binary Tree before removing duplicates (level order): ";
    printLevelOrder(originalTree);

    int *uniqueValues = new int[size];
    int uniqueCount = 0;
    collectUniqueLevelOrder(originalTree, uniqueValues, uniqueCount, size);

    Node *uniqueTree = buildTreeFromArray(uniqueValues, uniqueCount);
    cout << "Binary Tree after removing duplicates (level order): ";
    printLevelOrder(uniqueTree);

    simpleSort(uniqueValues, uniqueCount);
    Node *bstRoot = buildBSTFromSorted(uniqueValues, 0, uniqueCount - 1);
    cout << "BST in-order traversal: ";
    printInOrder(bstRoot);
    cout << endl;

    delete[] values;
    delete[] uniqueValues;
    freeTree(originalTree);
    freeTree(uniqueTree);
    freeTree(bstRoot);

    return 0;
}
