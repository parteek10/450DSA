// Problem Link : https://practice.geeksforgeeks.org/problems/ncr1019/1


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int nCr(int n, int r){
        // code here
        vector<int> data(r+1 , 0)  ;
        int mod = 1000000007 , i , j ;
        data[0] = 1 ; 
        for(i = 1 ; i<=n ; i++)  {
            for(j = min(i , r) ; j>0 ; j--)  {
                data[j] = (data[j] + data[j-1])%mod ;
            }
        }
        return data[r] ; 
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  
