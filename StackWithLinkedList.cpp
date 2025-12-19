#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next = NULL;
};

class Stack
{
    Node *top = NULL;

public:
    void push(int item)
    {
        Node *newNode = new Node();
        newNode->data = item;
        newNode->next = top;
        top = newNode;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
            return -1;
        }

        Node *current = top;
        int value = current->data;

        top = top->next;
        delete current;

        return value;
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        else
        {
            return top->data;
        }
    }
    bool isEmpty()
    {
        return top == NULL;
    }

    void Display()
    {
        Node *current = top;
        if (top == NULL)
        {
            cout << "Stack is Empty";
        }
        else
        {
            cout << "Element: ";
            while (current != NULL)
            {
                cout << current->data << " ";
                current = current->next;
            }
        }
    }
};

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.Display();
    st.pop();
    st.Display();
}