#include <iostream>
using namespace std;
struct Node
{
    int data = 0;
    Node *pre, *next = NULL;
};

class DLL
{
    Node *head = NULL;

public:
    void insertNode(int item)
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
    }
    void Delete(int key)
    {
        Node *current = head;

        while (current != nullptr)
        {
            if (current->data == key)
            {
                if (current->pre != nullptr)
                    current->pre->next = current->next;
                else
                    head = current->next;

                if (current->next != nullptr)
                    current->next->pre = current->pre;

                delete current;
                return;
            }
            current = current->next;
        }

        cout << "Element Not Found!" << endl;
    }
};
int main()
{
    DLL list;

    // Insert elements
    list.insertNode(10);
    list.insertNode(20);
    list.insertNode(30);
    list.insertNode(40);

    cout << "List elements: ";
    list.DisplayElements();

    // Search
    int index = list.Search(30);
    cout << "Index of 30: " << index << endl;

    // Delete middle
    list.Delete(20);
    cout << "After deleting 20: ";
    list.DisplayElements();

    // Delete head
    list.Delete(10);
    cout << "After deleting 10: ";
    list.DisplayElements();

    // Delete tail
    list.Delete(40);
    cout << "After deleting 40: ";
    list.DisplayElements();

    // Delete non-existing
    list.Delete(100);

    return 0;
}
