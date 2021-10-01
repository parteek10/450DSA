// Max profit by selling stocks at most k times
#include <bits/stdc++.h>
using namespace std;

// function to calculate max Profit by selling stock at most k times
int maxProfit(int k, int n, int price[])
{
    // code here
    int dp[k + 1][n];

    // intialising 2d-matrix
    for (int i = 0; i <= k; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 0;

    for (int i = 1; i <= k; i++)
    {
        int prevDiff = INT_MIN;
        for (int j = 1; j <= n - 1; j++)
        {
            prevDiff = max(prevDiff, dp[i - 1][j - 1] - price[j - 1]);
            // at every jth day, there can be two possibilities , either i transactions are done upto jth day
            // or ith transaction on jth day
            dp[i][j] = max(dp[i][j - 1], price[j] + prevDiff);
        }
    }

    return dp[k][n - 1];
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        int price[n];
        for (int i = 0; i < n; i++)
        {
            cin >> price[i];
        }

        cout << maxProfit(k, n, price);
    }
    return 0;
}
