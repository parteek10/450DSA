// Problem link : https://practice.geeksforgeeks.org/problems/edit-distance3702/1

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
   
    int countDist(string &s , string &t , vector<vector<int> > &dp , int i , int j )  {
        if(i == 0 || j == 0 ) 
           return i+j ; 
        
        if(dp[i][j] != -1 ) 
          return dp[i][j] ; 
        
        if(s[i-1] == t[j-1]) {
            return dp[i][j] = countDist(s , t , dp , i-1 , j-1) ; 
        }
        else {
            dp[i-1][j] = countDist(s , t , dp , i-1 , j) ; //remove
            dp[i-1][j-1] = countDist(s , t , dp , i-1 , j-1) ; //replace
            dp[i][j-1] = countDist(s , t , dp , i , j-1) ; //insert
            return dp[i][j] = 1+ min(dp[i-1][j] , min(dp[i-1][j-1] , dp[i][j-1])) ; 
        }
    }
   
    int editDistance(string s, string t) {
        // Code here
        int n = s.size() , m = t.size() ; 
        vector<vector<int> > dp(n+1 , vector<int>(m+1 , -1)) ; 
        
        return countDist(s ,t , dp , n , m ) ; 
    }
};


int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
