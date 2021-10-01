// problem link : https://practice.geeksforgeeks.org/problems/reverse-a-string/1

#include<bits/stdc++.h>
void reverseString(vector<char>& s) 
{
    for(int i=0; i<s.size()/2; i++) 
	{
        char temp = s[i];
    	s[i] = s[s.size() - 1 - i];
        s[s.size() - 1 - i] = temp;
    }
}
