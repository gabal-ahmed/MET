#include "iostream"
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class LinkedList
{
    Node *head = NULL;

public:
    void InsertNode(int item)
    {
        Node *newNode = new Node();
        newNode->data = item;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *currnet = head;
            while (currnet->next != NULL)
            {
                currnet = currnet->next;
            }
            currnet->next = newNode;
        }
    }
    void DisplayElements()
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
    int Search(int item)
    {
        int index = 0;
        Node *current = head;

        while (current != NULL)
        {
            if (current->data == item)
            {
                return index;
            }
            current = current->next;
            index++;
        }
        cout << "Target Not Found";
        return -1;
        // return index;
    }
    void Delete(int key, int asd)
    {
        Node *pre, *current = head;
        while (current != NULL)
        {
            if (current->data == key)
            {
                pre->next = current->next;
                delete current;

                return;
            }
            pre = current;
            current = current->next;
        }
        cout << "Element Not Found!";
    }
};
int main()
{
    LinkedList ls;
    ls.InsertNode(10);
    ls.InsertNode(20);
    int index = ls.Search(20);
    ls.Delete(20, 20);
    ls.DisplayElements();
    return 0;
}