#include <iostream>
#include <cctype>
using namespace std;

char stack[100];
int top = -1;

bool isEmpty() { return top == -1; }
void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }

int CheckP(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string InfixToPostFix(string infix)
{
    string postfix = "";

    for (char c : infix)
    {
        if (isdigit(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                postfix += pop();
            }
            pop(); 
        }
        else 
        {
            while (!isEmpty() && CheckP(peek()) >= CheckP(c))
            {
                postfix += pop();
            }
            push(c);
        }
    }

    while (!isEmpty())
    {
        postfix += pop();
    }

    return postfix;
}

int main()
{
    cout << InfixToPostFix("1+2*3") << endl;
    cout << InfixToPostFix("(1+2*(5+1))*3") << endl;
}
