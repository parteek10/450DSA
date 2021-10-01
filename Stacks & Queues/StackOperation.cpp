#include <iostream>
using namespace std;
int top = -1;
int ch, arr[50];
void push(int element)
{
    if (top == 50)
    {
        cout << "STACK OVERFLOW" << endl;
    }
    else
    {
        top++;
        arr[top] = element;
    }
}
void pop()
{
    if (top < 0)
    {
        cout << "STACK UNDERFLOW" << endl;
    }
    else
    {
        top--;
    }
}
void display()
{
    if (top < 0)
    {
        cout << "STACK EMPTY" << endl;
    }
    else 
    {
        cout << "\n\n      YOUR STACK IS:\n";
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << "\t";
        }
    }
   
}

int main()
{

label:
    cout << "\n\n-------Select your choice-------\n\n1-push\n2-Pop\n3-Display\n4-Break\n\n";
    cin >> ch;
    cout << endl
         << endl;
    switch (ch)
    {

    case 1:
    {
        int element;
        cout << "Insert Element: ";
        cin >> element;
        push(element);
        goto label;
    }

    case 2:
    {
        pop();
        goto label;
    }

    case 3:
    {
        display();
        goto label;
    }

    case 4:
    {
        cout << "\n\nEXITING..........\n-----Exited Successfully\n\n";
        break;
    }
    }
    return 0;
}
