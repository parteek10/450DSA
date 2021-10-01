#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n, q, ind, varInd, s = 0;
    cin >> n >> q;
    int *arr[n];
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        arr[s] = new int[k];
        for (int j = 0; j < k; j++)
        {
            int f;
            cin >> f;
            arr[s][j] = f;
        }
        s++;
    }
    for (int i = 0; i < q; i++)
    {
        cin >> ind >> varInd;
        cout << arr[ind][varInd] << "\n";
    }

    return 0;
}
