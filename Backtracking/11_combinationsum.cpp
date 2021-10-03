// problem _no_11--https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1
#include <iostream>
#include <vector>
using namespace std;
// declaring a global vector
vector<vector<int>> ans;
void comb_sum(int i, vector<int> arr, vector<int> v, int sum)
{
    if (i == arr.size())
    {   // if sum == 0 means the target is achieved
        if (sum == 0) ans.push_back(v);
        return;
    }
    // if is used, to maintain the sum greater than 0;
    if (arr[i] <= sum)
    {
        v.push_back(arr[i]);
        comb_sum(i, arr, v, sum - arr[i]);
        v.pop_back();
    }
    comb_sum(i + 1, arr, v, sum);
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int sum = 7;
    vector<int> v;
    comb_sum(0, arr, v, sum);
    // ans vector stores all the possible solution of given sum;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
