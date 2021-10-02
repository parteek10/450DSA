//https://www.geeksforgeeks.org/permutation-coefficient/
#include<bits/stdc++.h>
using namespace std;
//function for permutation coefficient
int permutationCoeff(int n, int k)
{
    int fact[n + 1];// declaring an array
 

    fact[0]=1; //storing 1 in 1st index
    for(int i = 1; i <= n; i++)
    fact[i] = i * fact[i - 1];
 
    return fact[n] / fact[n - k];
}
 
// Driver Code
int main()
{
    int n , k ;
    cin>>n>>k;
     
    cout << permutationCoeff(n, k);
 
    return 0;
}
