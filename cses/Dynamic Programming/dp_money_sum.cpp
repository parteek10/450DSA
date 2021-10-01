#include<bits/stdc++.h>
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long
#define fi for(ll i=0;i<n;i++)
#define pb push_back
using namespace std;
int main()
{
	boost;
	ll n;
	cin>>n;
	ll coins[n];
	ll sum=0; 
	fi
	{
	  cin>>coins[i];
	  sum+=coins[i];
	}
	bool dp[n+1][sum+1];
	for(int i=0;i<=sum;i++)
	    dp[0][i]=false;
	for(int i=0;i<=n;i++)
	    dp[i][0]=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
				if(coins[i-1]<=j)
				{
					dp[i][j]=dp[i-1][j-coins[i-1]]|dp[i-1][j];
					
						}
				else
				 dp[i][j]=dp[i-1][j];
				 				
		}
		
		
			}	    
	
	set<int> s;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(dp[i][j])
			   s.insert(j);
			   
		}
	}
	cout<<s.size()<<'\n';
	for(auto x:s)
	   cout<<x<<" ";
	   cout<<"\n";
	    
	
	  




	return 0;

}


