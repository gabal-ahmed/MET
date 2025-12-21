#include <iostream>
using namespace std;
const int MAX = 5;
int top = -1;
int stack[MAX];
bool isEmpty()
{
    return top == -1;
};
bool isFull()
{
    return top == MAX - 1;
};
void push(int x)
{
    if (isFull())
    {
        cout << "Stack is Full!";
    }
    else
    {
        stack[++top] = x;
    }
}
int pop()
{
    if (isEmpty())
    {
        cout << "Stack is Empty!";
        return -1;
    }
    else
    {
        return stack[top--];
    }
};
int peek()
{
    if (isEmpty())
    {
        cout << "Stack is Empty";
        return -1;
    }
    else
    {
        return stack[top];
    }
};

struct Node
{
    char lable;
    bool visited = false;
};

Node *adjList[MAX];
int adjMatrix[MAX][MAX];
int vertexCount = 0;

void addVertex(char x)
{
    Node *vertex = new Node();
    vertex->lable = x;
    adjList[vertexCount++] = vertex;
}
void addEdge(int start, int end)
{
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
}
void displayVertex(int vertexIndex)
{
    cout << adjList[vertexIndex]->lable << endl;
};

int getAdjUnVistedVertex(int vertexIndex)
{
    for (int i = 0; i < vertexCount; i++)
    {
        if (adjMatrix[vertexIndex][i] == 1 && adjList[i]->visited == false)
        {
            return i;
        }
    }
    return -1;
};

void depthFirstSearch()
{
    adjList[0]->visited = true;
    displayVertex(0);
    push(0);
    while (!isEmpty())
    {
        int unvistedVertex = getAdjUnVistedVertex(peek());
        if (unvistedVertex == -1)
        {
            pop();
        }
        else
        {
            adjList[unvistedVertex]->visited = true;
            displayVertex(unvistedVertex);
            push(unvistedVertex);
        }
    }
};
int main()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    addVertex('S');
    addVertex('A');
    addVertex('B');
    addVertex('C');
    addVertex('D');
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(2, 4);
    addEdge(3, 4);
    cout << "DFS" << endl;
    depthFirstSearch();

    return 0;
}