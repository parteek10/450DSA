//heapsort

#include <bits/stdc++.h>
using namespace std;
  
void heapify(vector<int> &arr, int n, int i)
{
    int maxi = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
  
    // finding the maximum among arr[l], arr[r], arr[i]
    if (l < n && arr[l] > arr[maxi])
        maxi = l;
    if (r < n && arr[r] > arr[maxi])
        maxi = r;
  
    if (maxi != i) {
        swap(arr[i], arr[maxi]);
        heapify(arr, n, maxi);	// heapify the subtree
    }
}
  
void heapSort(vector<int> &arr)
{
	int n=arr.size();
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
  
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);   // putting the maximums elements at last
        heapify(arr, i, 0);		// i becomes the size of heap as a parameter to heapify
    }
}
  
  
int main()
{
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();
  
    heapSort(arr);
  
    cout << "After soring: \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}
