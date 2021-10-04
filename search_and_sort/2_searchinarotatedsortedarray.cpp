// https://leetcode.com/problems/search-in-rotated-sorted-array/
#include<iostream>
#include<vector>
using namespace std;

// 1-GET THE PEAK OF ARRAY
int getpeak(vector<int> v)
{   int s=0;
    int e=v.size()-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(mid<e and v[mid]>v[mid+1]) return mid;
        if(mid>s and v[mid]<v[mid-1]) return mid-1;
        if(v[mid]<=v[s]) e=mid-1;
        else  s=mid+1;
    }
    return -1;
}

// 2-USING BS TO GET THE TARGET 
 int bs(int key,vector<int> v,int s,int e)
{
      while(s<=e)
      {
          int mid=s+(e-s)/2;
          if (v[mid]==key)
          {
            return mid;
          }
          if (v[mid]<key)
          {
            s=mid+1;
          }
          if (v[mid]>key)
          {
            e=mid-1;
          } 
      }
      return -1;
}

// 3.MAIN FUNCTON
int search(vector<int>& nums, int target) {

       int ans=-1; // assuming that element is not present

    //    IF LENGTH = 0 MEANS EITHER TARGET WILL BE AT  0 OR NOT PRESENT
       if(nums.size()==1) 
            if(target==nums[0]) return 0;
             else return ans;

        if(nums.size()==2) 
            if(target==nums[0]) return 0;
            else if(target==nums[1]) return 1;
            else return ans;
        
        int peak=getpeak(nums); //GETTING THE PEAK
        int k=bs(target,nums,0,peak); // SEARCHING ELEMENT FROM [STRT] TO [PEAK]
        int l=bs(target,nums,peak+1,nums.size()-1); // SEARCHING ELEMENT FROM [PEAK+1] TO [end of vector]

        //CHECKING IF ELEMENT IS PRESENT IN LEFT AND RIGHT PART OR NOT
        if(k!=-1) ans=k;
        else if(l!=-1) ans=l;
        
        return ans;
    }
int main()
{
    // ORIGINAL ARRAY={0,1,2,4,5,6,7}
    vector<int> v={4,5,6,7,0,1,2};
    cout<<search(v,7);
    return 0;
}
