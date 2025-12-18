#include <iostream>
using namespace std;
class Stack
{

    static const int MaxSize = 10;
    int arr[MaxSize]{};
    int top = -1;

public:
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MaxSize - 1; }
    void push(int item)
    {
        if (!isFull())
        {
            arr[++top] = item;
        }
        else
        {
            cout << "Stack is Full!" << endl;
        }
    }
    int pop()
    {
        if (!isEmpty())
        {
            return arr[top--];
        }
        else
        {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!" << endl;
        }
        else
        {
            cout << "Element in top : " << arr[top] << endl;
        }
    }
    void DisplayElements()
    {
        if (top == -1)
        {
            cout << "Stack is Empty!" << endl;
        }
        else
        {
            cout << "Element in Stack: ";
            for (int i = 0; i < top + 1; i++)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.DisplayElements();
    s.pop();
    s.DisplayElements();
    s.peek();

    return 0;
}