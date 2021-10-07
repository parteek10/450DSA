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
void binarySearch(int *A, int size, int num)
{
    int strt=0,end=size-1,pos,mid,find;
      while(strt<=end)
    {
        mid=(strt+end)/2;
        if(num>A[mid])
        {
            strt=mid+1;
        }
        else if(num<A[mid])
        {
            end=mid-1;
        }
        else if(num==A[mid])
        {
            pos=mid;
            find++;
            break;
        } 
    }
    if(find==0)
    printf("Item not found");
    else
    printf("Item %d found at index %d ,position %d",num,pos,pos+1);
}

int main()
{
    int n, element;
    printf("Enter number of elements:");
    scanf("%d", &n);
    int *arr=(int*)malloc(n*sizeof(int));
    createArray(arr, n);
    printArray(arr, n);
    printf("Enter Element to search in array:");
    scanf("%d", &element);
    binarySearch(arr, n, element);
}
