#include<bits/stdc++.h>
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long
#define fi for(ll i=0;i<n;i++)
#define pb push_back
using namespace std;
int main()
{
	boost;
	string a,b;
	cin>>a>>b;
	int alength=a.size(),blength=b.size();
	// That there are 4 possiblities,we will take that one which gives us min no of operations
	int dp[alength+1][blength+1];

	for(int i=0;i<=blength;i++)
	    dp[0][i]=i;
	for(int i=0;i<=alength;i++) 
	    dp[i][0]=i;
dp[0][0]=0;

	for(int i=1;i<=alength;i++)
	{
		for(int j=1;j<=blength;j++)
		{
			dp[i][j]=1e9;
				if(i)
				{
					dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
					
					}
				if(j)
				{
					dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
					
							}
				if(i && j)
				{
					if(a[i-1]!=b[j-1])
					{
						dp[i][j]=min(dp[i][j],1+dp[i-1][j-1]);
						
					}
					else
					{
							dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
					}
					
										}						
		}
	}   
	
	cout<<dp[alength][blength]<<'\n'; 
		   
	
	




	return 0;

}


