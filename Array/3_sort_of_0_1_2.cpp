//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i<n ; i++){
        cin>>arr[i];
    }
    //created a count array which will keep the track of number of 0's,1's,2's in the array
    int count[3] = {0,0,0}; 
    for(int i = 0 ; i<n ; i++){
        int k = arr[i];
        count[k]++;
    }
    int x = 0;
    for(int i = 0 ;i<3 ; i++){
        while(count[i]>0){   // substituting the values of 0's ,1's and 2's at thier sorted positions in main array
            arr[x] = i;
            x++;
            count[i]--;
        }
    }
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i];
    }
}
