// Problem Link : https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  cout<<findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}


// arr[] : the input array
// N : size of the array arr[]

// return the length of the longest subsequene of consecutive integers
int findLongestConseqSubseq(int arr[], int n)
{
    unordered_map<int, bool> m;
    int maxval=-1;
    for(int i=0; i<n; i++) {
        m[arr[i]] = true;
        maxval = max(maxval, arr[i]);
    }
    int count=0, maxcount=0;
    for(int i=0; i<=maxval; i++) {
        if(m[i]) {
            count++;
        } else {
            count=0;
        }
        maxcount= max(maxcount, count);
    }
    return maxcount;
}
