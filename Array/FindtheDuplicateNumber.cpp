#include<bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]==nums[i])
                return nums[i];
        }
    }
main()
{
  int n;
  cin>>n;
  vector<int> nums(n);
  for(auto &ele:nums)
  {
    cin>>ele;
  }
  cout<<findDuplicate(nums);
}
