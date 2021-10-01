#include <iostream>
using namespace std;
int main()
{
    int num, item, ind;
    cout << "Enter Number of elements ";
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    cout << "old array is \n";

    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n Enter New Element and index \n";
    cin >> item;
    cin >> ind; //  1 2 _ 4 5  6 _   //1 2 3 4 5
                  //0 1 2 3 4  5 6

    for (int i = num; i >= ind; i--)  // i->2  ind->2
    {
        arr[i + 1] = arr[i];
    }
    num = num + 1;
    arr[ind] = item;

    cout<<"\n New Array after innsertion is: \n";

    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << " ";
    }
}
