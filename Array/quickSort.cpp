#include <stdio.h>

void createArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d:", i + 1);
        scanf("%d", &A[i]);
    }
}

void printArray(int A[], int n)
{
    printf("\nArray is\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n\n");
}

int partition(int arr[], int low, int high)
{
    int i, j, pivot;
    pivot = arr[low];
    i = low+1;
    j = high;
    //3 42 5 6 78 5
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    } while (i < j);

    // Swap A[low] and A[j]
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int arr[], int low, int high)
{
    int partitionIndex;
    if (high > low)
    {
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main()
{
    int n, low, high;
    low = 0;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    high = n - 1;
    int arr[n];
    createArray(arr, n);
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    printArray(arr, n);
}
