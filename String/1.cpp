// Problem link : https://practice.geeksforgeeks.org/problems/palindrome-string0817/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    int isPalin=1;
	    
	    int firstIndex = 0;
	    int lastIndex = S.length()-1;
	    
	    while(firstIndex<lastIndex){
	        if(S[firstIndex]!=S[lastIndex]){
	            isPalin=0;
	            break;
	        } else {
	            firstIndex++;
	            lastIndex--;
	        }
	    }
	    
	    return isPalin;
	}

};

int main(){

    Solution s;

    string demoString = "abba";
    int res = s.isPalindrome(demoString);
    if(res==1){
        cout<<"String is Palindrome\n";
    } else {
        cout<<"String is not Palindrome\n";
    }

    return 0;
}