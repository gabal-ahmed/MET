#include <iostream>
using namespace std;

struct Node
{
    int data = 0;
    Node *left, *right = NULL;
};
class Tree
{
    Node *root = NULL;

public:
    Node *InsertNodeInTree(Node *root, int item)
    {
        if (root == NULL)
        {
            Node *newNode = new Node();
            newNode->data = item;
            return newNode;
        }

        if (item > root->data)
            root->right = InsertNodeInTree(root->right, item);
        else
            root->left = InsertNodeInTree(root->left, item);

        return root;
    }

    void InOrder(Node *root)
    {
        if (root == NULL)
            return;

        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
};

int main()
{
    Tree tree;
    Node *root = tree.InsertNodeInTree(NULL, 10);
    root = tree.InsertNodeInTree(root, 60);
    root = tree.InsertNodeInTree(root, 5);
    root = tree.InsertNodeInTree(root, 70);
    root = tree.InsertNodeInTree(root, 6);
    root = tree.InsertNodeInTree(root, 3);
    root = tree.InsertNodeInTree(root, 90);
    root = tree.InsertNodeInTree(root, 50);
    tree.InOrder(root);

    return 0;
}