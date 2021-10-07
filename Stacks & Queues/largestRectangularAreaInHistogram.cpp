#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
  long long getMaxArea(long long arr[], int n){
    stack<long long>s;
    vector<long long>left;
    vector<long long>right;
    for(int i=n-1;i>=0;i--)
    {
        if(s.empty())
        {
            right.push_back(n);
            s.push(i);
        }
        else if(!s.empty()&&arr[i]>arr[s.top()])
        {
            right.push_back(i+1);
            s.push(i);
        }
        else if(!s.empty()&&arr[i]<=arr[s.top()])
        {
            while(!s.empty()&&arr[i]<=arr[s.top()])
            s.pop();
            
            if(!s.empty())
            {
                right.push_back(s.top());
                s.push(i);
            }
            else
            {
                right.push_back(n);
                s.push(i);
            }
        }
        
    }
    reverse(right.begin(),right.end());
    while(!s.empty())
    s.pop();
    for(int i=0;i<n;i++)
    {
        if(s.empty())
        {
            left.push_back(-1);
            s.push(i);
        }
        else if(!s.empty()&&arr[i]>arr[s.top()])
        {
             left.push_back(i-1);
            s.push(i);
        }
         else if(!s.empty()&&arr[i]<=arr[s.top()])
        {
            while(!s.empty()&&arr[i]<=arr[s.top()])
            s.pop();
            
            if(!s.empty())
            {
                left.push_back(s.top());
                s.push(i);
            }
            else
            {
                left.push_back(-1);
                s.push(i);
            }
        }
    }
    long long k,max=0;
    for(int i=0;i<n;i++)
    {
        k=((right[i]-1)-(left[i]+1)+1)*arr[i];
        if(k>max)
        max=k;
    }
    return max;
    
}
};

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
