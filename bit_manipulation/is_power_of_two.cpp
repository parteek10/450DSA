#include <bits/stdc++.h>
using namespace std;

bool check(int n) 
{ 
    if (n == 0) 
        return false; 	// 0 is not power of 2
    while (n != 1) 
    { 
        if (n%2 != 0) 
            return false; 	// remainder is 1 and n!=1 , that means it is not power of 2
        n = n/2; 
    } 
    return true; 
} 

int main() 
{ 
	int n=31;
	
    if(check(n))
    	cout<<n<<" is power of 2.\n";
    else 
    	cout<<n<<" is not power of 2.\n";
    return 0; 
} 
