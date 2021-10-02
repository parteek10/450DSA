// link for problem: https://practice.geeksforgeeks.org/problems/coin-change2448/1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long int count(int S[], int m, int n)
{
	vector<long long int> v;
	for(long long int i=0; i<=n; i++)
	{
		v.push_back(0);
	}
	v[0] = 1;
	for(long long int i=0; i<m; i++)
	{
		for(long long int j=S[i]; j<=n; j++)
		{
			v[j] += v[j-S[i]];
		}
	}
	return v[n];
}


int main(void)
{
//	#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
//	#endif
	long long int t;
	cout<<"Enter number of test cases : ";
	cin>>t;
	while(t--)
	{
		long long int m;
		cout<<"Enter size of array : ";
		cin>>m;
		long long int arr[m];
		cout<<"Enter price array : ";
		for(long long int i=0; i<m; i++)
		{
			cin>>arr[i];
		}
		long long int n;
		cout<<"Enter target sum : ";
		cin>>n;
		cout<<"Number of ways possible : "<<count(arr, m, n)<<endl;
	}
	return 0;
}

