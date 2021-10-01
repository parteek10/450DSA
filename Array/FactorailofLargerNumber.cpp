// Problem Link : https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void multiply(vector<int> &result , int num )  {
        int carry = 0 , val , i , n = result.size() ; 
        for(i = 0 ; i < n ; i++)  {
            val = result[i]*num + carry ; 
            result[i] = val%10 ; 
            carry = val/10 ;
        }
        while(carry != 0 )  {
            result.push_back(carry%10) ; 
            carry = carry/10 ; 
        }
        return ; 
    }
    
    vector<int> factorial(int N){
        // code here
        vector<int> result ;
        result.push_back(1) ; 
        for(int i = 1 ; i <=N ; i++ )  
            multiply(result , i ) ; 
        
        int i = 0 , j = result.size()-1 ;
        while(i<j)  {
            swap(result[i] , result[j]) ; 
            i++ ; j-- ;
        }
        return result ; 
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  
