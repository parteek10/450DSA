#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void MaxMin(int arr[], int low, int high, int &ma, int &mi)
{
    if (low == high)
    {
        ma = max(arr[low], ma);
        mi = min(arr[low], mi);
        return;
    }
    if (high - low == 1)
    {
        ma = max(max(arr[low], arr[high]), ma);
        mi = min(min(arr[low], arr[high]), mi);
        return;
    }
    int mid = (low + high) / 2;
    MaxMin(arr, low, mid, ma, mi);
    MaxMin(arr, mid + 1, high, ma, mi);
}

int main()
{
    int n;
    cout << "ENTER THE SIZE OF THE ARRAY: ";
    cin >> n;
    int a[n];
    cout << "\nENTER THE ELEMENTS: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "\nARRAY IS: ";
    print(a, n);
    int ma = INT_MIN, mi = INT_MAX;
    MaxMin(a, 0, n - 1, ma, mi);
    cout << "\nMINIMUM ELEMENT: " << mi;
    cout << "\nMAXIMUM ELEMENT: " << ma << endl;
    return 0;
}
