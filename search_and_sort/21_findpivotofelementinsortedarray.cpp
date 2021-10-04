// http://theoryofprogramming.com/2017/12/16/find-pivot-element-sorted-rotated-array/
#include<iostream>
#include<vector>
using namespace std;

//to get highest element in sorted array
int pivot(vector<int> v)
{   int s=0;
    int e=v.size()-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(mid<e and v[mid]>v[mid+1]) return mid;
        if(mid>s and v[mid]<v[mid-1]) return mid-1;
        if(v[mid]<=v[s]) e=mid-1;
        else  s=mid+1;
    }
    return -1;
}
int main()
{
    vector<int> arr={4,5,6,8,9,1,2};
    cout<<pivot(arr);
    return 0;
}
