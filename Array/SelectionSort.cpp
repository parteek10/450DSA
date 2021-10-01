#include <iostream>
using namespace std;
int minimum(int arr[],int num,int loc)
{

    int min = arr[0],ind;
    for (int i = 0; i < num; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
           ind=i;
        }
    }
   arr[ind]+=arr[loc];   //3 2 1 5 6   //min=4  arr=1 min=3
   arr[loc]=arr[ind]-arr[loc];
   arr[ind]=arr[ind]-arr[loc];

}

int main()
{
    int element, ind,min,loc=0;
    int num;

    cout << "Enter Number of element\n";
    cin >> num;
    int arr[num];
    cout << "\nEnter the elements \n";

    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
     for (int i = 0; i < num; i++)
    {
        minimum(arr,num,loc);
        loc++;
        
    }
     
       for (int i = 0; i < num; i++)
    {
        cout<< arr[i]<<" ";
    }

    
}
