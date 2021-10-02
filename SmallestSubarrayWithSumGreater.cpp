
#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        // Your code goes here   
        int l=0,r=0,s=0,len=INT_MAX;
        while(l<n&&r<n)
        {
            if(arr[r]+s<=x)
            {
                s+=arr[r];
                r++;
            }
            else
            {
                len=min(len,r-l+1);
                s-=arr[l];
                l++;
            }
        }
        return len;
    }
};


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.sb(a,n,x)<<endl;
	}
	return 0;
}  
