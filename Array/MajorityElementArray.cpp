#include <iostream>
using namespace std;
void getArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << " ";
        cin >> arr[i];
    }
}

void printArray(int *arr, int n)
{
    cout << "         -------Your Entered Array is--------\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Element at position " << i + 1 << ": " << arr[i] << "\n";
    }
}

int majorityElement(int *arr, int n)
{
    int frequency = 0, item=-1,value=n/2;
    for (int i = 0; i < n; i++)
    {
        frequency=0;
        for (int j = 0; j < n; j++)
        {
            
            if (arr[j] == arr[i])
            {
                frequency++;
            }

        }
        if (frequency>value)
        {
            item = arr[i];
            break;
        }
    }
    //cout<<item;
    return item;
}

int main()

{
    int n, sum;
    cout << "Enter number of elements in array: ";
    cin >> n;
    int arr[n];
    getArray(arr, n);
    //printArray(arr, n);
    int winner = majorityElement(arr, n);
    if (winner != -1)
        cout << "\n             Majority Element is " << winner;
    else
        cout << "    \n!!!Sorry!Majority Element not Exist in given array!";
}



//scanf("%[^\n]%*c", s);
