#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll catalan(unsigned int n)
{
    // Base case
    if (n <= 1)
        return 1;

    ll ans = 0;
    // can understand it by number of BST examples
    // for every ith node, there can be catalan(i-1)*catalan(n-i) possibilties
    for (int i = 1; i <= n; i++)
        ans += catalan(i - 1) * catalan(n - i);

    return ans;
}

// Driver code
int main()
{
    for (int i = 0; i < 10; i++)
        cout << catalan(i) << " ";
    return 0;
}
