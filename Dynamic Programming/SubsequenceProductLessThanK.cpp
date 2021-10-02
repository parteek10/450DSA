// Problem link : https://www.geeksforgeeks.org/count-subsequences-product-less-k/

#include <bits/stdc++.h>
using namespace std;

int productLessThanK (vector<int>& a, int k) {
    int dp[a.size()+1][k+1];
    memset(dp, 0, sizeof(dp));

    for (int i=1; i<=a.size(); i++) {
        for (int j=1; j<=k; j++) {
            if (a[i-1]<=j) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j/a[i-1]]+1;        
                        // here one is added as a subsequence with just a[i-1] is also possible
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[a.size()][k];
}

int main()
{
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    int k = 10;
    cout << productLessThanK(A, k) << endl;
}
