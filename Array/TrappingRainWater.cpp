// Problem link  : https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

#include<bits/stdc++.h>
using namespace std;
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        int lw = 0 , ub = n-1 ;
        int leftmax = 0 , rightmax = 0 ; 
        int water = 0 ;
        while(lw <= ub )  {
            if(arr[lw] < arr[ub] )  {
                if(arr[lw] < leftmax) 
                  water += leftmax - arr[lw] ; 
                else 
                   leftmax = arr[lw] ; 
                lw++ ;
            }
            else {
                if(arr[ub] >= rightmax ) 
                    rightmax = arr[ub] ; 
                else 
                   water += rightmax - arr[ub] ; 
                ub-- ; 
            }
        }
        return water ; 
    }
};

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
} 
