//https://practice.geeksforgeeks.org/viewSol.php?subId=34a054eed1c6d94d059cf82b27372516&pid=703903&user=mewtwo28
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		    sort(v.begin(), v.end());
		    int n=v.size();
		    if(n%2==0){
		        return (v[n/2]+v[(n-1)/2])/2;
		    }
		    else{
		        return v[n/2];
		    }
		}
};


int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
    return 0;
}
  
