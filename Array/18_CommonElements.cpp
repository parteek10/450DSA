#include <iostream>
using namespace std;
 
// This function prints common elements in ar1
void isPresent(int *ar1, int *ar2, int *ar3, int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;
 
    while (i < n1 && j < n2 && k < n3)
    {
        
         if (ar1[i] == ar2[j] && ar2[j] == ar3[k])
         {   cout << ar1[i] << " ";   i++; j++; k++; }
 
         
         else if (ar1[i] < ar2[j])
             i++;
 
       
         else if (ar2[j] < ar3[k])
             j++;
 
         else
             k++;
    }
}
 
// Driver code
int main()
{
    int n1,n2,n3;
    cout<<"Enter number of element for array1 array2 and array3: ";
    cin>>n1>>n2>>n3;
    int ar1[n1],ar2[n2],ar3[n3];

    cout<<"Enter elements in array 1:"<<endl;
    for(int i=0;i<n1;i++)
    {
        cin>>ar1[i];
    }

    cout << "Enter elements in array 2:" << endl;
    for (int i = 0; i < n2; i++)
    {
        cin>>ar2[i];
    }

    cout << "Enter elements in array 3:" << endl;
    for (int i = 0; i < n3; i++)
    {
        cin >> ar3[i];
    }

    cout << "Common Elements is/are ";
    isPresent(ar1, ar2, ar3, n1, n2, n3);
    return 0;
}
