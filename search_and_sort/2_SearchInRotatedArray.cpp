// Link : https://leetcode.com/problems/search-in-rotated-sorted-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
      int low=0,high=nums.size()-1;

      while (low <= high) {

        int mid=low + ((high - low) / 2);
        if (nums[mid]==target) 
          return mid;
        
        if (nums[low]<=nums[mid]) {
          if (nums[low]<=target && target<nums[mid])
            high= mid - 1;
          else
            low= mid + 1;
        }
         
        else {
          if (nums[mid]<target && target<=nums[high])
            low= mid + 1;
          else
            high= mid - 1;
        }
      }
      return -1;
         
    }
};
//example input inside main
int main(){
  vector<int> nums;
  nums.push_back(4);
  nums.push_back(5);
  nums.push_back(6);
  nums.push_back(7);
  nums.push_back(0);
  nums.push_back(1);
  nums.push_back(2);
  int target=0;
  Solution ob;
  cout<<ob.search(nums,target);
 return 0; 
}
