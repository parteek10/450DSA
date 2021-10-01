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

void bubbleSort_adaptive(int A[], int n)
{
    printf("Using adaptive bubble sort:\n");
    int isSorted = 0, pass = 0;
    for (int i = 0; i < n - 1; i++)
    {
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++) //3 2 4 5 6 7
        {

            if (A[j] > A[j + 1])
            {
                A[j] = A[j] + A[j + 1];
                A[j + 1] = A[j] - A[j + 1];
                A[j] = A[j] - A[j + 1];
                isSorted = 0;
            }
        }
        pass++;
        if (isSorted)
        {
            printf("\n   Sorting done in %d pass/passes\n\n", pass);
            return;
        }
    }
}

void bubbleSort(int A[], int n)
{
    printf("Using Non adaptive bubble sort:\n");
    int pass = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {

            if (A[j] > A[j + 1])
            {
                A[j] = A[j] + A[j + 1];
                A[j + 1] = A[j] - A[j + 1];
                A[j] = A[j] - A[j + 1];
            }
        }
        pass++;   
    }
    printf("\n   Sorting done in %d passes\n\n", pass);
}

int main()
{
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    createArray(arr, n);
    printArray(arr, n);
    bubbleSort_adaptive(arr, n);
    //bubbleSort(arr, n);
    printArray(arr, n);
}

