// find majority element

#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> a)
{
    // using map to store the count of each number appearing in array    
    unordered_map<int,int>mp;
    int n= a.size();
    
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }
    for(int i=0;i<n;i++){
        if(mp[a[i]]>(n/2))		//majority element found
            return a[i];
    }
    return -1;
}

int main(){
	vector<int> arr ={ 1,2,1,1,1,4,5,1};
	cout<<majorityElement(arr);
}
