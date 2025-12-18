#include <iostream>
using namespace std;
class Queue
{
    int front = 0, rear = 0;
    static const int MAXSIZE = 100;
    int arr[MAXSIZE]{};

public:
    bool IsEmpty()
    {
        return front >= rear;
    }
    bool IsFull()
    {
        return rear == MAXSIZE;
    }
    void Enqueue(int data)
    {
        if (!IsFull())
        {
            arr[rear++] = data;
        }
        else
        {
            cout << "Queue Is Full!" << endl;
        }
    }
    int Dequeue()
    {
        if (IsEmpty())
            return 0;
        int data = arr[front];
        front = front + 1;
        return data;
    }

    void DisplayElements()
    {
        if (IsEmpty())
            cout << "Queue is Empty!" << endl;
        else
        {
            cout << "Elements in Queue: ";
            for (int i = front; i < rear; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
    int Peek()
    {
        if (IsEmpty())
        {
            return 0;
        }
        else
        {
            return arr[front];
        }
    }
};
int main()
{
    Queue qu;
    qu.Enqueue(10);
    qu.Enqueue(20);
    qu.Enqueue(30);
    qu.DisplayElements();
    int ele = qu.Dequeue();
    qu.DisplayElements();

    return 0;
}