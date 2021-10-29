#include <iostream>
using namespace std;
void getArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1<<" ";
        cin >> arr[i];
    }
}
void printArray(int *arr, int n)
{
    cout<<"         -------Your Entered Array is--------\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Element at position "<<i+1<<": "<<arr[i]<<"\n";
    }
}

int sumArray(int arr[],int n)
{
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    return sum;
    
}
int main()

{
    int n, sum;
    cout << "Enter number of elements in array: ";
    cin >> n;
    int arr[n];
    getArray(arr, n);
    printArray(arr,n);
    int summ=sumArray(arr,n);
    cout<<"\n       ----->Sum of all elements of array is: "<<summ;
}
